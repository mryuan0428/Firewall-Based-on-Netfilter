/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QLabel *label;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QStringLiteral("MessageDialog"));
        MessageDialog->resize(340, 150);
        label = new QLabel(MessageDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 300, 51));
        label->setMinimumSize(QSize(300, 0));
        label->setMaximumSize(QSize(300, 16777215));
        pushButton_ok = new QPushButton(MessageDialog);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(130, 100, 80, 30));
        pushButton_ok->setMinimumSize(QSize(80, 30));
        pushButton_ok->setMaximumSize(QSize(80, 30));
        pushButton_cancel = new QPushButton(MessageDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(230, 100, 80, 30));
        pushButton_cancel->setMinimumSize(QSize(80, 30));
        pushButton_cancel->setMaximumSize(QSize(80, 30));

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MessageDialog", "TextLabel", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("MessageDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("MessageDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
