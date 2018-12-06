#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>


namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = 0);
    ~MessageDialog();
    void setMessage(QString message);

private:
    Ui::MessageDialog *ui;

signals:
    void actionSignal(bool);
private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
};

#endif // MESSAGEDIALOG_H
