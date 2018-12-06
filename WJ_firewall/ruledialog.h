#ifndef RULEDIALOG_H
#define RULEDIALOG_H

#include <QDialog>
#include "common.h"


namespace Ui {
class RuleDialog;
}

class RuleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RuleDialog(QWidget *parent = 0);
    ~RuleDialog();

private slots:
    void on_pushButton_ok_clicked();

    void on_comboBox_protocol_currentTextChanged(const QString &text);

    void on_pushButton_cancel_clicked();

    void on_comboBox_time_currentTextChanged(const QString &text);

private:
    Ui::RuleDialog *ui;

signals:
    void addNewRuleSignal(rule_str_tp);
};

#endif // RULEDIALOG_H
