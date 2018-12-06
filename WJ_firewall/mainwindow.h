#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "common.h"
#include "ruledialog.h"
#include "messagedialog.h"
#include "ruledialog_m.h"
extern char controlinfo[1000];

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString runShell(QString cmd);
    bool isModLoaded();
    bool sendRuleToFirewall();
    bool setRuleStringFile();
    bool getRuleStringFile();
    void updateRuleNo();

private slots:
    void on_pushButton_addRule_clicked();
    void on_pushButton_delRule_clicked();
    void on_pushButton_fiterOn_clicked();
    void on_pushButton_fiterOff_clicked();
    void addRuleString(rule_str_tp ruleString);
    void modRuleString(rule_str_tp ruleString);
    void delRuleString(bool action);
    void updateLog();
    void on_pushButton_logClean_clicked();
    void on_pushButton_modRule_clicked();

    void on_action_importRules_triggered();

    void on_action_exportRules_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *label_runStatus;
    RuleDialog *addRuleDialog;
    MessageDialog *delRuleDialog;
    ruledialog_m *modRuleDialog;
    QTableWidget *rulesTable;
    QList<rule_str_tp> ruleStringList;
    QTimer *logTimer;
};

#endif // MAINWINDOW_H
