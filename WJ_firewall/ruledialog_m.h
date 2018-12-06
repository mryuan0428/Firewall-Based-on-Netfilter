#ifndef RULEDIALOG_M_H
#define RULEDIALOG_M_H

#include <QDialog>
#include "common.h"
extern rule_str_tp modrule;

namespace Ui {
class ruledialog_m;
}

class ruledialog_m : public QDialog
{
    Q_OBJECT

public:
    explicit ruledialog_m(QWidget *parent = 0);
    ~ruledialog_m();

private:
    Ui::ruledialog_m *ui;
signals:
    void modRuleSignal(rule_str_tp);

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
    void on_comboBox_protocol_currentTextChanged(const QString &text);
};

#endif // RULEDIALOG_M_H
