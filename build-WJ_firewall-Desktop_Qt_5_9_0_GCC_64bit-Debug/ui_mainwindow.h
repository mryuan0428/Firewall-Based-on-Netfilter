/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_importRules;
    QAction *action_exportRules;
    QAction *action_exitAPP;
    QAction *action_about;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_addRule;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_modRule;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_delRule;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_fiterOn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_fiterOff;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_logClean;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_help;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(1000, 600));
        action_importRules = new QAction(MainWindow);
        action_importRules->setObjectName(QStringLiteral("action_importRules"));
        action_exportRules = new QAction(MainWindow);
        action_exportRules->setObjectName(QStringLiteral("action_exportRules"));
        action_exitAPP = new QAction(MainWindow);
        action_exitAPP->setObjectName(QStringLiteral("action_exitAPP"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_addRule = new QPushButton(centralWidget);
        pushButton_addRule->setObjectName(QStringLiteral("pushButton_addRule"));
        pushButton_addRule->setMinimumSize(QSize(100, 30));
        pushButton_addRule->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButton_addRule);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_modRule = new QPushButton(centralWidget);
        pushButton_modRule->setObjectName(QStringLiteral("pushButton_modRule"));
        pushButton_modRule->setMinimumSize(QSize(100, 30));
        pushButton_modRule->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButton_modRule);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_delRule = new QPushButton(centralWidget);
        pushButton_delRule->setObjectName(QStringLiteral("pushButton_delRule"));
        pushButton_delRule->setMinimumSize(QSize(100, 30));
        pushButton_delRule->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButton_delRule);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_fiterOn = new QPushButton(centralWidget);
        pushButton_fiterOn->setObjectName(QStringLiteral("pushButton_fiterOn"));
        pushButton_fiterOn->setMinimumSize(QSize(100, 30));
        pushButton_fiterOn->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButton_fiterOn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_fiterOff = new QPushButton(centralWidget);
        pushButton_fiterOff->setObjectName(QStringLiteral("pushButton_fiterOff"));
        pushButton_fiterOff->setMinimumSize(QSize(100, 30));
        pushButton_fiterOff->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButton_fiterOff);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab:selected{background-color:  white;}\n"
"QTabBar::tab:!selected{background-color: rgb(239, 235, 231);}\n"
"QTabBar::tab{min-width:80px; min-height:28px; border: 1px solid rgb(188, 185, 181); margin-bottom:1px;}"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tab_1->setFocusPolicy(Qt::NoFocus);
        tab_1->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(tab_1);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("margin:-1px;"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(85);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(60);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);

        verticalLayout_2->addWidget(tableWidget);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_logClean = new QPushButton(tab_2);
        pushButton_logClean->setObjectName(QStringLiteral("pushButton_logClean"));

        verticalLayout_3->addWidget(pushButton_logClean);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setStyleSheet(QStringLiteral("margin:-1px;"));
        plainTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("padding-left:20px;"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_file->addAction(action_importRules);
        menu_file->addAction(action_exportRules);
        menu_file->addAction(action_exitAPP);
        menu_help->addAction(action_about);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WJ firewall", Q_NULLPTR));
        action_importRules->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\350\247\204\345\210\231", Q_NULLPTR));
        action_exportRules->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\350\247\204\345\210\231", Q_NULLPTR));
        action_exitAPP->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        action_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        pushButton_addRule->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\247\204\345\210\231", Q_NULLPTR));
        pushButton_modRule->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\247\204\345\210\231", Q_NULLPTR));
        pushButton_delRule->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\247\204\345\210\231", Q_NULLPTR));
        pushButton_fiterOn->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\350\277\207\346\273\244", Q_NULLPTR));
        pushButton_fiterOff->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\350\277\207\346\273\244", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "NO", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "SADDR", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "SPORT", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "DADDR", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "DPORT", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "TIME_FLAG", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "TIME_BEGIN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "TIME_END", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "PROTOCOL", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "ACTION", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "\350\247\204\345\210\231", Q_NULLPTR));
        pushButton_logClean->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\227\245\345\277\227", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\227\245\345\277\227", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
