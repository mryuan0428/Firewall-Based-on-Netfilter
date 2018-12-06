#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutdialog::aboutdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutdialog)
{
    ui->setupUi(this);
}

void aboutdialog::setMessage(QString message)
{
    QFont ft;
    ft.setPointSize(11);
    ui->label->setFont(ft);
    ui->label->setText(message);
}

aboutdialog::~aboutdialog()
{
    delete ui;
}

void aboutdialog::on_pushButton_ok_clicked()
{
    this->close();
}
