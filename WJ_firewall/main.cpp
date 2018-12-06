#include "mainwindow.h"
#include <QApplication>

rule_str_tp modrule;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(QApplication::desktop()->screenGeometry().center()- w.rect().center());
    w.show();

    return a.exec();
}
