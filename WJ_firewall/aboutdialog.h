#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QFont>

namespace Ui {
class aboutdialog;
}

class aboutdialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutdialog(QWidget *parent = 0);
    void setMessage(QString message);
    ~aboutdialog();

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::aboutdialog *ui;
};

#endif // ABOUTDIALOG_H
