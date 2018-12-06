/********************************************************************************
** Form generated from reading UI file 'ruledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEDIALOG_H
#define UI_RULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RuleDialog
{
public:
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_src_ip;
    QLineEdit *lineEdit_src_port;
    QLineEdit *lineEdit_dst_port;
    QLineEdit *lineEdit_dst_ip;
    QComboBox *comboBox_time;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_protocol;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox_action;
    QComboBox *comboBox_log;

    void setupUi(QDialog *RuleDialog)
    {
        if (RuleDialog->objectName().isEmpty())
            RuleDialog->setObjectName(QStringLiteral("RuleDialog"));
        RuleDialog->resize(600, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RuleDialog->sizePolicy().hasHeightForWidth());
        RuleDialog->setSizePolicy(sizePolicy);
        RuleDialog->setMinimumSize(QSize(600, 250));
        RuleDialog->setMaximumSize(QSize(600, 250));
        pushButton_ok = new QPushButton(RuleDialog);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(400, 200, 60, 25));
        pushButton_cancel = new QPushButton(RuleDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(490, 200, 60, 25));
        label = new QLabel(RuleDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 67, 25));
        label_2 = new QLabel(RuleDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 67, 25));
        label_3 = new QLabel(RuleDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 67, 25));
        label_4 = new QLabel(RuleDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 60, 67, 25));
        lineEdit_src_ip = new QLineEdit(RuleDialog);
        lineEdit_src_ip->setObjectName(QStringLiteral("lineEdit_src_ip"));
        lineEdit_src_ip->setGeometry(QRect(110, 20, 150, 25));
        lineEdit_src_port = new QLineEdit(RuleDialog);
        lineEdit_src_port->setObjectName(QStringLiteral("lineEdit_src_port"));
        lineEdit_src_port->setGeometry(QRect(110, 60, 150, 25));
        lineEdit_dst_port = new QLineEdit(RuleDialog);
        lineEdit_dst_port->setObjectName(QStringLiteral("lineEdit_dst_port"));
        lineEdit_dst_port->setGeometry(QRect(400, 60, 150, 25));
        lineEdit_dst_ip = new QLineEdit(RuleDialog);
        lineEdit_dst_ip->setObjectName(QStringLiteral("lineEdit_dst_ip"));
        lineEdit_dst_ip->setGeometry(QRect(400, 20, 150, 25));
        comboBox_time = new QComboBox(RuleDialog);
        comboBox_time->setObjectName(QStringLiteral("comboBox_time"));
        comboBox_time->setGeometry(QRect(110, 110, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_time->sizePolicy().hasHeightForWidth());
        comboBox_time->setSizePolicy(sizePolicy);
        label_5 = new QLabel(RuleDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 110, 67, 25));
        label_6 = new QLabel(RuleDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 110, 67, 25));
        comboBox_protocol = new QComboBox(RuleDialog);
        comboBox_protocol->setObjectName(QStringLiteral("comboBox_protocol"));
        comboBox_protocol->setGeometry(QRect(400, 110, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_protocol->sizePolicy().hasHeightForWidth());
        comboBox_protocol->setSizePolicy(sizePolicy);
        label_7 = new QLabel(RuleDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 150, 67, 25));
        label_8 = new QLabel(RuleDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 150, 67, 25));
        comboBox_action = new QComboBox(RuleDialog);
        comboBox_action->setObjectName(QStringLiteral("comboBox_action"));
        comboBox_action->setGeometry(QRect(400, 150, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_action->sizePolicy().hasHeightForWidth());
        comboBox_action->setSizePolicy(sizePolicy);
        comboBox_log = new QComboBox(RuleDialog);
        comboBox_log->setObjectName(QStringLiteral("comboBox_log"));
        comboBox_log->setGeometry(QRect(110, 150, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_log->sizePolicy().hasHeightForWidth());
        comboBox_log->setSizePolicy(sizePolicy);

        retranslateUi(RuleDialog);

        QMetaObject::connectSlotsByName(RuleDialog);
    } // setupUi

    void retranslateUi(QDialog *RuleDialog)
    {
        RuleDialog->setWindowTitle(QApplication::translate("RuleDialog", "\346\267\273\345\212\240\350\247\204\345\210\231", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("RuleDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("RuleDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("RuleDialog", "\346\272\220\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RuleDialog", "\346\272\220\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("RuleDialog", "\347\233\256\347\232\204\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("RuleDialog", "\347\233\256\347\232\204\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lineEdit_src_ip->setText(QApplication::translate("RuleDialog", "any", Q_NULLPTR));
        lineEdit_src_port->setText(QApplication::translate("RuleDialog", "any", Q_NULLPTR));
        lineEdit_dst_port->setText(QApplication::translate("RuleDialog", "any", Q_NULLPTR));
        lineEdit_dst_ip->setText(QApplication::translate("RuleDialog", "any", Q_NULLPTR));
        label_5->setText(QApplication::translate("RuleDialog", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("RuleDialog", "\345\215\217\350\256\256\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("RuleDialog", "\345\212\250\344\275\234\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("RuleDialog", "\346\227\245\345\277\227\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RuleDialog: public Ui_RuleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEDIALOG_H
