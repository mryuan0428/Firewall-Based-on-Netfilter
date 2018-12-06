#include "mainwindow.h"
#include "ui_mainwindow.h"
char controlinfo[1600];
int numa=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //主窗口初始化设置
    ui->setupUi(this);
    addRuleDialog = new RuleDialog(this);
    delRuleDialog = new MessageDialog(this);
    aboutDialog = new aboutdialog(this);
    delRuleDialog->setMessage("确定要删除吗？");
    label_runStatus = new QLabel();
    label_runStatus->setAlignment(Qt::AlignHCenter);
    label_runStatus->setMinimumHeight(25);
    ui->statusBar->addWidget(label_runStatus);
    rulesTable = ui->tableWidget;
    rulesTable->horizontalHeader()->setMinimumHeight(30);
    rulesTable->setColumnWidth(1, 150);
    rulesTable->setColumnWidth(3, 150);
    rulesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    rulesTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    rulesTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Stretch);
    rulesTable->horizontalHeader()->setSectionResizeMode(9, QHeaderView::Stretch);
    rulesTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    logTimer = new QTimer(this);

    //check mod
    if (isModLoaded()){
        ui->pushButton_fiterOn->setEnabled(false);
        label_runStatus->setText("运行状态：已启动");
        logTimer->start(LOG_UPDATE_TIME); //every 100ms fresh the log
    }else{
        ui->pushButton_fiterOff->setEnabled(false);
        label_runStatus->setText("运行状态：未启动");
    }

    //connect
    connect(addRuleDialog, SIGNAL(addNewRuleSignal(rule_str_tp)),
            this, SLOT(addRuleString(rule_str_tp)));
    connect(delRuleDialog, SIGNAL(actionSignal(bool)),
            this, SLOT(delRuleString(bool)));

    connect(logTimer, SIGNAL(timeout()), this, SLOT(updateLog()));

    //set table
    getRuleStringFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::runShell(QString cmd)
{
    //执行shell命令，调用脚本
    QProcess *shell = new QProcess(this);
    shell->start(cmd);
    shell->waitForFinished();
    return shell->readAll();
}

bool MainWindow::isModLoaded()
{
    return runShell("bash ../bin/main.sh ckmod") == "true";
}

bool MainWindow::sendRuleToFirewall()
{
    //将ruleStringList发送个防火墙内核模块
    if (!isModLoaded()){
        return false;
    }

    int count = 0; //记录规则数量
    //规则转化为字符串再发送
    foreach(rule_str_tp ruleString, ruleStringList){
        if (ruleFromString_new(ruleString, (controlinfo+(count*32)))){
            count++;
        }
        if (count > RULE_COUNT_MAX){
            return false;
        }
    }
    int fp;
    fp =open("/dev/controlinfo",O_RDWR,S_IRUSR|S_IWUSR);
    if (fp > 0)
    {
        write(fp,controlinfo,count*32);
    }
    else {
        QMessageBox::critical(this, "错误", "无法打开controlinfo！");
        return false;
    }
    ::close(fp);

    return true;
}

bool MainWindow::setRuleStringFile()
{
    //将有改动的ruleStringList更新到rule.txt文档
    QDir dir("../data/");
    if (!dir.exists()){
        dir.mkdir("../data/");
    }
    QFile f("../data/rule.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QMessageBox::critical(this, "错误", "无法打开rule.txt！");
        return false;
    }
    QTextStream stream(&f);
    foreach (rule_str_tp ruleString, ruleStringList) {
        QString temp = ruleString.src_addr + "%"
                + ruleString.dst_addr + "%"
                + ruleString.src_port + "%"
                + ruleString.dst_port + "%"
                + ruleString.time_flag + "%"
                + ruleString.hour_begin + "%"
                + ruleString.min_begin + "%"
                + ruleString.hour_end + "%"
                + ruleString.min_end + "%"
                + ruleString.protocol;
        stream << temp << endl;
    }
    f.close();
    return true;
}

bool MainWindow::getRuleStringFile()
{
    //打开规则文件
    QFile f("../data/rule.txt");
    if (!f.exists()){
        return false;
    }
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "错误", "无法打开rule.txt！");
        return false;
    }
    QTextStream stream(&f);

    //逐条取规则并显示，存储在ruleStringList
    while (!stream.atEnd()){
        QString lineStr = stream.readLine();
        QStringList lineSpilt = lineStr.split("%");
        if (lineSpilt.length() != 10){
            continue;
        }
        rule_str_tp ruleString;
        ruleString.src_addr = lineSpilt[0];
        ruleString.dst_addr = lineSpilt[1];
        ruleString.src_port = lineSpilt[2];
        ruleString.dst_port = lineSpilt[3];
        ruleString.time_flag = lineSpilt[4];
        ruleString.hour_begin = lineSpilt[5];
        ruleString.min_begin = lineSpilt[6];
        ruleString.hour_end = lineSpilt[7];
        ruleString.min_end = lineSpilt[8];
        ruleString.protocol = lineSpilt[9];

        if (ruleAddrCheck(ruleString.src_addr) &&ruleAddrCheck(ruleString.dst_addr) &&
            rulePortCheck(ruleString.src_port) &&rulePortCheck(ruleString.dst_port))
        {addRuleString(ruleString);}
    }
    return true;
}

void MainWindow::updateRuleNo()
{
    for (int i=0; i<rulesTable->rowCount(); i++){
        rulesTable->item(i, 0)->setText(QString::number(i+1));
    }
}

void MainWindow::on_pushButton_addRule_clicked()
{
    if (ruleStringList.length() >= 50){
        QMessageBox::information(this, "提示", "规则数量已达上限！");
        return;
    }
    addRuleDialog->exec();
    setRuleStringFile();
    sendRuleToFirewall();
}

void MainWindow::on_pushButton_delRule_clicked()
{
    if (rulesTable->currentRow() < 0){
        QMessageBox::information(this, "提示", "请先选中要删除的规则！");
        return;
    }
    delRuleDialog->exec();
    setRuleStringFile();
    sendRuleToFirewall();
}

void MainWindow::on_pushButton_fiterOn_clicked()
{
    QString ret = runShell("bash ../bin/main.sh insmod");
    if (ret == "pkexec"){
        QMessageBox::critical(this, "错误", "请先安装pkexec");
    }
    if (isModLoaded()){
        if (!logTimer->isActive()){
            logTimer->start(LOG_UPDATE_TIME);
        }
        label_runStatus->setText("运行状态：已启动");
        ui->pushButton_fiterOn->setEnabled(false);
        ui->pushButton_fiterOff->setEnabled(true);
    }
    sendRuleToFirewall();
}

void MainWindow::on_pushButton_fiterOff_clicked()
{
    QString ret = runShell("bash ../bin/main.sh rmmod");
    if (ret == "pkexec"){
        QMessageBox::critical(this, "错误", "请先安装pkexec！");
    }
    if (!isModLoaded()){
        if (logTimer->isActive()){
            logTimer->stop();
        }
        ui->pushButton_fiterOn->setEnabled(true);
        ui->pushButton_fiterOff->setEnabled(false);
        label_runStatus->setText("运行状态：未启动");
    }
}

void MainWindow::addRuleString(rule_str_tp ruleString)
{
    //将单条规则添加至ruleStringList
    ruleStringList.append(ruleString);
    int row = ruleStringList.length();
    rulesTable->setRowCount(row);
    rulesTable->setItem(row - 1, 0, new QTableWidgetItem(""));
    rulesTable->setItem(row - 1, 1, new QTableWidgetItem(ruleString.src_addr));
    rulesTable->setItem(row - 1, 2, new QTableWidgetItem(ruleString.src_port));
    rulesTable->setItem(row - 1, 3, new QTableWidgetItem(ruleString.dst_addr));
    rulesTable->setItem(row - 1, 4, new QTableWidgetItem(ruleString.dst_port));
    rulesTable->setItem(row - 1, 5, new QTableWidgetItem(ruleString.time_flag));
    rulesTable->setItem(row - 1, 6, new QTableWidgetItem(ruleString.hour_begin+':'+ruleString.min_begin));
    rulesTable->setItem(row - 1, 7, new QTableWidgetItem(ruleString.hour_end+':'+ruleString.min_end));
    rulesTable->setItem(row - 1, 8, new QTableWidgetItem(ruleString.protocol));
    rulesTable->setItem(row - 1, 9, new QTableWidgetItem("reject"));
    for (int i=0; i<rulesTable->columnCount(); ++i){
        rulesTable->item(row - 1, i)->setTextAlignment(Qt::AlignCenter);
    }
    updateRuleNo();
}

void MainWindow::modRuleString(rule_str_tp ruleString)
{
    ruleStringList[numa]=ruleString;
    rulesTable->setItem(numa, 0, new QTableWidgetItem(""));
    rulesTable->setItem(numa, 1, new QTableWidgetItem(ruleString.src_addr));
    rulesTable->setItem(numa, 2, new QTableWidgetItem(ruleString.src_port));
    rulesTable->setItem(numa, 3, new QTableWidgetItem(ruleString.dst_addr));
    rulesTable->setItem(numa, 4, new QTableWidgetItem(ruleString.dst_port));
    rulesTable->setItem(numa, 5, new QTableWidgetItem(ruleString.time_flag));
    rulesTable->setItem(numa, 6, new QTableWidgetItem(ruleString.hour_begin+':'+ruleString.min_begin));
    rulesTable->setItem(numa, 7, new QTableWidgetItem(ruleString.hour_end+':'+ruleString.min_end));
    rulesTable->setItem(numa, 8, new QTableWidgetItem(ruleString.protocol));
    rulesTable->setItem(numa, 9, new QTableWidgetItem("reject"));
    for (int i=0; i<rulesTable->columnCount(); ++i){
        rulesTable->item(numa, i)->setTextAlignment(Qt::AlignCenter);
    }
    updateRuleNo();
}

void MainWindow::delRuleString(bool action)
{
    //从ruleStringList和rulesTable中删除规则
    if (action){
        int rowIndex = rulesTable->currentRow();
        if (rowIndex >= 0){
            rulesTable->removeRow(rowIndex);
            ruleStringList.removeAt(rowIndex);
        }
        rulesTable->setRowCount(ruleStringList.length());
    }
    updateRuleNo();
}

void MainWindow::updateLog()
{
    QStringList ret = runShell("bash ../bin/log.sh").split("\n");
    QDir dir("../data/");
    if (!dir.exists()){
        dir.mkdir("../data/");
    }
    QFile f("../data/log.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QMessageBox::critical(this, "错误", "无法打开log.txt！");
    }
    QTextStream stream(&f);
    foreach (QString line, ret) {
        if (line.split(">").length() < 2){
            continue;
        }
        ui->plainTextEdit->appendPlainText(line.split(">")[1] + "\n");
        stream << line.split(">")[1] << endl;
    }
    f.close();
}

void MainWindow::on_pushButton_logClean_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_pushButton_modRule_clicked()
{
    numa=rulesTable->currentRow();
    if (numa < 0){
        QMessageBox::information(this, "提示", "请先选中要修改的规则！");
        return;
    }

    modrule=ruleStringList[numa];
    modRuleDialog = new ruledialog_m(this);
    connect(modRuleDialog, SIGNAL(modRuleSignal(rule_str_tp)),
            this, SLOT(modRuleString(rule_str_tp)));
    modRuleDialog->exec();
    setRuleStringFile();
    sendRuleToFirewall();
}

void MainWindow::on_action_importRules_triggered()
{
    //---获取文件名
    QString fileName = QFileDialog :: getOpenFileName(this,tr("导入规则"),"/home","");
    if(fileName.isNull()) return;

        //---打开文件并读取文件内容
        QFile file(fileName);

        //--打开文件成功
        if (file.open(QIODevice ::ReadOnly | QIODevice ::Text))
        {
            QTextStream textStream(&file);
            QString line=textStream.readAll();
                //---写入防火墙rule.txt
                QFile f("../data/rule.txt");
                if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
                    QMessageBox::critical(this, "错误", "无法打开rule.txt！");
                    return;
                }
                QTextStream stream(&f);
                stream << line << endl;
                file.close();  //success ro XieRu
                f.close();

                //更新rulelist
                QFile fn("../data/rule.txt");
                if (!fn.open(QIODevice::ReadOnly | QIODevice::Text)){
                    QMessageBox::critical(this, "错误", "无法打开rule.txt！");
                    return;
                }
                QTextStream instream(&fn);
                QList<rule_str_tp> ruleStringList_tmp;

                rulesTable->setRowCount(0);
                rulesTable->clearContents();

                while (!instream.atEnd()){
                    QString lineStr = instream.readLine();
                    QStringList lineSpilt = lineStr.split("%");
                    if (lineSpilt.length() != 10){
                        continue;
                    }
                    rule_str_tp ruleString;
                    ruleString.src_addr = lineSpilt[0];
                    ruleString.dst_addr = lineSpilt[1];
                    ruleString.src_port = lineSpilt[2];
                    ruleString.dst_port = lineSpilt[3];
                    ruleString.time_flag = lineSpilt[4];
                    ruleString.hour_begin = lineSpilt[5];
                    ruleString.min_begin = lineSpilt[6];
                    ruleString.hour_end = lineSpilt[7];
                    ruleString.min_end = lineSpilt[8];
                    ruleString.protocol = lineSpilt[9];

                    if (ruleAddrCheck(ruleString.src_addr) &&ruleAddrCheck(ruleString.dst_addr) &&
                        rulePortCheck(ruleString.src_port) &&rulePortCheck(ruleString.dst_port))
                    {
                        ruleStringList_tmp.append(ruleString);
                        int row = ruleStringList_tmp.length();
                        rulesTable->setRowCount(row);
                        rulesTable->setItem(row - 1, 0, new QTableWidgetItem(""));
                        rulesTable->setItem(row - 1, 1, new QTableWidgetItem(ruleString.src_addr));
                        rulesTable->setItem(row - 1, 2, new QTableWidgetItem(ruleString.src_port));
                        rulesTable->setItem(row - 1, 3, new QTableWidgetItem(ruleString.dst_addr));
                        rulesTable->setItem(row - 1, 4, new QTableWidgetItem(ruleString.dst_port));
                        rulesTable->setItem(row - 1, 5, new QTableWidgetItem(ruleString.time_flag));
                        rulesTable->setItem(row - 1, 6, new QTableWidgetItem(ruleString.hour_begin+':'+ruleString.min_begin));
                        rulesTable->setItem(row - 1, 7, new QTableWidgetItem(ruleString.hour_end+':'+ruleString.min_end));
                        rulesTable->setItem(row - 1, 8, new QTableWidgetItem(ruleString.protocol));
                        rulesTable->setItem(row - 1, 9, new QTableWidgetItem("reject"));
                        for (int i=0; i<rulesTable->columnCount(); ++i){
                            rulesTable->item(row - 1, i)->setTextAlignment(Qt::AlignCenter);
                        }
                        updateRuleNo();
                    }
                } //rulelist和ruletable更新完成
                ruleStringList = ruleStringList_tmp;
                fn.close();

        }
        else	//---打开文件失败
        {
            QMessageBox ::information(NULL, NULL, "open file error");
        }
        sendRuleToFirewall();

}

void MainWindow::on_action_exportRules_triggered()
{
    QFileDialog fileDialog;
       QString fileName = fileDialog.getSaveFileName(this,tr("导出规则"),"/home","");
       if(fileName.isNull()) return;
       if(fileName == "")
           return;
       QFile file(fileName);
       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
           return;
       }
       else
       {
           QTextStream textStream(&file);

           foreach (rule_str_tp ruleString, ruleStringList) {
                   QString temp = ruleString.src_addr + "%"
                           + ruleString.dst_addr + "%"
                           + ruleString.src_port + "%"
                           + ruleString.dst_port + "%"
                           + ruleString.time_flag + "%"
                           + ruleString.hour_begin + "%"
                           + ruleString.min_begin + "%"
                           + ruleString.hour_end + "%"
                           + ruleString.min_end + "%"
                           + ruleString.protocol;
                   textStream <<temp << endl;
               }
            textStream<<'\n'<<"- Meaning: ---------------------------------------------------------------------------------"<<'\n'<<endl;
            textStream<<"|     SIP      |     DIP      | SPort | DPort | Time | SHour | SMin | EHour | EMin | Protocol |"<<endl;
           foreach (rule_str_tp ruleString, ruleStringList) {
                   QString temp = '|'+ruleString.src_addr.rightJustified(14,' ')+'|'
                           + ruleString.dst_addr.rightJustified(14,' ')+'|'
                           + ruleString.src_port.rightJustified(7,' ')+'|'
                           + ruleString.dst_port.rightJustified(7,' ')+'|'
                           + ruleString.time_flag.rightJustified(6,' ')+'|'
                           + ruleString.hour_begin.rightJustified(7,' ')+'|'
                           + ruleString.min_begin.rightJustified(6,' ')+'|'
                           + ruleString.hour_end.rightJustified(7,' ')+'|'
                           + ruleString.min_end.rightJustified(6,' ')+'|'
                           + ruleString.protocol.rightJustified(10,' ')+'|';
                   textStream << temp << endl;
               }

           QMessageBox::warning(this,tr("提示"),tr("保存文件成功"));
           file.close();
       }

}

void MainWindow::on_action_exitAPP_triggered()
{
    this->close();
}

void MainWindow::on_action_about_triggered()
{
    aboutDialog->setMessage("- 开发环境：\n"
                              "         操作系统：Ubuntu 15.10 \n"
                              "         内核版本：4.2.0-16-generic \n"
                              "         开发软件：Qt 5.9.0 \n"
                              "         编译器：gcc version 5.2.1 \n\n"
                              "- 作者：WJ_Yuan \n"
                              "           mryuan0428@sjtu.edu.cn \n\n"
                              "        Copyright (c) 2018 WJ_YUAN");
    aboutDialog->exec();
}
