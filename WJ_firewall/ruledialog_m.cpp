#include "ruledialog_m.h"
#include "ui_ruledialog_m.h"

ruledialog_m::ruledialog_m(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ruledialog_m)
{
    ui->setupUi(this);
    ui->comboBox_action->addItem("reject");
    //ui->comboBox_action->addItem("permit");
    ui->comboBox_log->addItem("yes");
    //ui->comboBox_log->addItem("no");
    //ui->comboBox_protocol->addItem("any");
    ui->comboBox_protocol->addItem("tcp");
    ui->comboBox_protocol->addItem("udp");
    ui->comboBox_protocol->addItem("icmp");
    ui->comboBox_time->addItem("any");
    //ui->comboBox_time->addItem("work");

    ui->lineEdit_src_ip->setText(modrule.src_addr);
    ui->lineEdit_dst_ip->setText(modrule.dst_addr);
    ui->lineEdit_src_port->setText(modrule.src_port);
    ui->lineEdit_dst_port->setText(modrule.dst_port);
    ui->comboBox_time->setCurrentText(modrule.time);
    ui->comboBox_protocol->setCurrentText(modrule.protocol);
    ui->comboBox_log->setCurrentText(modrule.log);
    ui->comboBox_action->setCurrentText(modrule.action);

}

ruledialog_m::~ruledialog_m()
{
    delete ui;
}

void ruledialog_m::on_pushButton_ok_clicked()
{
    rule_str_tp rule_str;

    rule_str.action = ui->comboBox_action->currentText();
    rule_str.time = ui->comboBox_time->currentText();
    rule_str.protocol = ui->comboBox_protocol->currentText();
    rule_str.log = ui->comboBox_log->currentText();

    rule_str.src_addr = ui->lineEdit_src_ip->text().trimmed();
    rule_str.dst_addr = ui->lineEdit_dst_ip->text().trimmed();
    if (!ruleAddrCheck(rule_str.src_addr) || !ruleAddrCheck(rule_str.dst_addr)){
        QMessageBox::critical(this, "错误", "请输入正确的ip地址！");
        return;
    }

    rule_str.src_port = ui->lineEdit_src_port->text().trimmed();
    rule_str.dst_port = ui->lineEdit_dst_port->text().trimmed();
    if (!rulePortCheck(rule_str.src_port) || !rulePortCheck(rule_str.dst_port)){
        QMessageBox::critical(this, "错误", "请输入正确的端口号（0-65535）！");
        return;
    }

    emit modRuleSignal(rule_str);
    this->close();

    return;
}

void ruledialog_m::on_comboBox_protocol_currentTextChanged(const QString &text)
{
    if (text == "icmp"){
        ui->lineEdit_src_port->setText("any");
        ui->lineEdit_dst_port->setText("any");
        ui->lineEdit_src_port->setEnabled(false);
        ui->lineEdit_dst_port->setEnabled(false);
    } else{
        ui->lineEdit_src_port->setEnabled(true);
        ui->lineEdit_dst_port->setEnabled(true);
    }
}

void ruledialog_m::on_pushButton_cancel_clicked()
{
    this->close();
}
