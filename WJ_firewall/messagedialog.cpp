#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    this->setFixedSize(340, 150);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::setMessage(QString message)
{
    ui->label->setText(message);
}

void MessageDialog::on_pushButton_ok_clicked()
{
    emit actionSignal(true);
    this->close();
}

void MessageDialog::on_pushButton_cancel_clicked()
{
    emit actionSignal(false);
    this->close();
}
