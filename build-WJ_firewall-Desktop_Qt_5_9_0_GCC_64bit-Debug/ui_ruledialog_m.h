/********************************************************************************
** Form generated from reading UI file 'ruledialog_m.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEDIALOG_M_H
#define UI_RULEDIALOG_M_H

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

class Ui_ruledialog_m
{
public:
    QLabel *label_2;
    QComboBox *comboBox_time;
    QLineEdit *lineEdit_src_port;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_src_ip;
    QLineEdit *lineEdit_dst_ip;
    QLabel *label_3;
    QLabel *label_5;
    QComboBox *comboBox_log;
    QComboBox *comboBox_protocol;
    QLabel *label_8;
    QComboBox *comboBox_action;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_dst_port;

    void setupUi(QDialog *ruledialog_m)
    {
        if (ruledialog_m->objectName().isEmpty())
            ruledialog_m->setObjectName(QStringLiteral("ruledialog_m"));
        ruledialog_m->resize(600, 250);
        label_2 = new QLabel(ruledialog_m);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 67, 25));
        comboBox_time = new QComboBox(ruledialog_m);
        comboBox_time->setObjectName(QStringLiteral("comboBox_time"));
        comboBox_time->setGeometry(QRect(110, 110, 150, 25));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_time->sizePolicy().hasHeightForWidth());
        comboBox_time->setSizePolicy(sizePolicy);
        lineEdit_src_port = new QLineEdit(ruledialog_m);
        lineEdit_src_port->setObjectName(QStringLiteral("lineEdit_src_port"));
        lineEdit_src_port->setGeometry(QRect(110, 60, 150, 25));
        label_6 = new QLabel(ruledialog_m);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 110, 67, 25));
        label_7 = new QLabel(ruledialog_m);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 150, 67, 25));
        lineEdit_src_ip = new QLineEdit(ruledialog_m);
        lineEdit_src_ip->setObjectName(QStringLiteral("lineEdit_src_ip"));
        lineEdit_src_ip->setGeometry(QRect(110, 20, 150, 25));
        lineEdit_dst_ip = new QLineEdit(ruledialog_m);
        lineEdit_dst_ip->setObjectName(QStringLiteral("lineEdit_dst_ip"));
        lineEdit_dst_ip->setGeometry(QRect(400, 20, 150, 25));
        label_3 = new QLabel(ruledialog_m);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 67, 25));
        label_5 = new QLabel(ruledialog_m);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 110, 67, 25));
        comboBox_log = new QComboBox(ruledialog_m);
        comboBox_log->setObjectName(QStringLiteral("comboBox_log"));
        comboBox_log->setGeometry(QRect(110, 150, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_log->sizePolicy().hasHeightForWidth());
        comboBox_log->setSizePolicy(sizePolicy);
        comboBox_protocol = new QComboBox(ruledialog_m);
        comboBox_protocol->setObjectName(QStringLiteral("comboBox_protocol"));
        comboBox_protocol->setGeometry(QRect(400, 110, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_protocol->sizePolicy().hasHeightForWidth());
        comboBox_protocol->setSizePolicy(sizePolicy);
        label_8 = new QLabel(ruledialog_m);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 150, 67, 25));
        comboBox_action = new QComboBox(ruledialog_m);
        comboBox_action->setObjectName(QStringLiteral("comboBox_action"));
        comboBox_action->setGeometry(QRect(400, 150, 150, 25));
        sizePolicy.setHeightForWidth(comboBox_action->sizePolicy().hasHeightForWidth());
        comboBox_action->setSizePolicy(sizePolicy);
        label = new QLabel(ruledialog_m);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 67, 25));
        label_4 = new QLabel(ruledialog_m);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 60, 67, 25));
        pushButton_cancel = new QPushButton(ruledialog_m);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(490, 200, 60, 25));
        pushButton_ok = new QPushButton(ruledialog_m);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(400, 200, 60, 25));
        lineEdit_dst_port = new QLineEdit(ruledialog_m);
        lineEdit_dst_port->setObjectName(QStringLiteral("lineEdit_dst_port"));
        lineEdit_dst_port->setGeometry(QRect(400, 60, 150, 25));

        retranslateUi(ruledialog_m);

        QMetaObject::connectSlotsByName(ruledialog_m);
    } // setupUi

    void retranslateUi(QDialog *ruledialog_m)
    {
        ruledialog_m->setWindowTitle(QApplication::translate("ruledialog_m", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("ruledialog_m", "\346\272\220\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lineEdit_src_port->setText(QApplication::translate("ruledialog_m", "any", Q_NULLPTR));
        label_6->setText(QApplication::translate("ruledialog_m", "\345\215\217\350\256\256\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ruledialog_m", "\345\212\250\344\275\234\357\274\232", Q_NULLPTR));
        lineEdit_src_ip->setText(QApplication::translate("ruledialog_m", "any", Q_NULLPTR));
        lineEdit_dst_ip->setText(QApplication::translate("ruledialog_m", "any", Q_NULLPTR));
        label_3->setText(QApplication::translate("ruledialog_m", "\347\233\256\347\232\204\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ruledialog_m", "\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("ruledialog_m", "\346\227\245\345\277\227\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ruledialog_m", "\346\272\220\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ruledialog_m", "\347\233\256\347\232\204\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("ruledialog_m", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("ruledialog_m", "\347\241\256\345\256\232", Q_NULLPTR));
        lineEdit_dst_port->setText(QApplication::translate("ruledialog_m", "any", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ruledialog_m: public Ui_ruledialog_m {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEDIALOG_M_H
