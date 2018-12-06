#include "ruledialog.h"
#include "ui_ruledialog.h"

RuleDialog::RuleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RuleDialog)
{
    ui->setupUi(this);
    ui->comboBox_protocol->addItem("tcp");
    ui->comboBox_protocol->addItem("udp");
    ui->comboBox_protocol->addItem("icmp");
    ui->comboBox_time->addItem("yes");
    ui->comboBox_time->addItem("no");
    ui->timeEdit->setDisplayFormat("HH:mm");
    ui->timeEdit_2->setDisplayFormat("HH:mm");
}

RuleDialog::~RuleDialog()
{
    delete ui;
}

void RuleDialog::on_pushButton_ok_clicked()
{
    rule_str_tp rule_str;

    //获取规则IP地址
    rule_str.src_addr = ui->lineEdit_src_ip->text().trimmed();
    rule_str.dst_addr = ui->lineEdit_dst_ip->text().trimmed();
    if (!ruleAddrCheck(rule_str.src_addr) || !ruleAddrCheck(rule_str.dst_addr)){
        QMessageBox::critical(this, "错误", "请输入正确的ip地址！");
        return;
    }

    //获取规则端口
    rule_str.src_port = ui->lineEdit_src_port->text().trimmed();
    rule_str.dst_port = ui->lineEdit_dst_port->text().trimmed();
    if (!rulePortCheck(rule_str.src_port) || !rulePortCheck(rule_str.dst_port)){
        QMessageBox::critical(this, "错误", "请输入正确的端口号（0-65535）！");
        return;
    }

    //获取时间设置信息以及报文类型
    rule_str.time_flag = ui->comboBox_time->currentText();
    rule_str.hour_begin = ui->timeEdit->sectionText(QTimeEdit::HourSection);
    rule_str.min_begin = ui->timeEdit->sectionText(QTimeEdit::MinuteSection);
    rule_str.hour_end = ui->timeEdit_2->sectionText(QTimeEdit::HourSection);
    rule_str.min_end = ui->timeEdit_2->sectionText(QTimeEdit::MinuteSection);
    rule_str.protocol = ui->comboBox_protocol->currentText();

    emit addNewRuleSignal(rule_str);
    this->close();

    return;
}

void RuleDialog::on_comboBox_protocol_currentTextChanged(const QString &text)
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

void RuleDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

void RuleDialog::on_comboBox_time_currentTextChanged(const QString &text)
{
    if(text == "no"){
        ui->timeEdit->setEnabled(false);
        ui->timeEdit_2->setEnabled(false);
    }
    else{
        ui->timeEdit->setEnabled(true);
        ui->timeEdit_2->setEnabled(true);
    }
}
