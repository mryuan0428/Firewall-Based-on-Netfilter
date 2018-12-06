#ifndef COMMON_H
#define COMMON_H

#include <QButtonGroup>
#include <QDebug>
#include <QDesktopWidget>
#include <QDir>
#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QMetaType>
#include <QProcess>
#include <QRadioButton>
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QTextStream>
#include <QTimer>
#include <QVariant>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE0   0x01
#define BYTE1   0x02
#define BYTE2   0x04
#define BYTE3   0x08
#define BYTE4   0x10
#define BYTE5   0x20
#define BYTE6   0x40
#define BYTE7   0x80

#define RULE_COUNT_MAX  50

#define FIREWALL_IOCTL_RULE 1
#define FIREWALL_IOCTL_LOG  2

#define LOG_UPDATE_TIME 100 //ms



/*
 *flag bit0: action
 *flag bit1: time
 *flag bit2: protocol
 *flag bit3: log
 *flag bit4: src_port
 *flag bit5: dst_port
 *flag bit6: src_addr
 *flag bit7: dst_addr
 */
struct rule_tp
{
    quint8 flag;
    quint8 protocol;
    quint8 days;        //bit0:sun, bit1:mon, ..., bit6:sat
    quint16 bg_time;	//from 00:00 to 23:59
    quint16 ed_time;
    quint16 src_port;
    quint16 dst_port;
    quint32 src_addr;
    quint32 dst_addr;
    quint32 src_mask;
    quint32 dst_mask;
};




struct rule_str_tp  //保存规则信息
{
    QString src_addr;
    QString dst_addr;
    QString src_port;
    QString dst_port;
    QString time;
    QString protocol;
    QString log;
    QString action;
};

bool ruleFromString(rule_str_tp ruleString, rule_tp &rule);
bool ruleFromString_new(rule_str_tp ruleString, char *p_controlinfo);
bool ruleAddrCheck(QString addrString);
bool rulePortCheck(QString portString);

#endif // COMMON_H
