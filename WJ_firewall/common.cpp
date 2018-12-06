#include "common.h"

QList<rule_str_tp> ruleStringList;

bool ruleFromString_new(rule_str_tp ruleString, char *p_controlinfo)
{
    unsigned int controlled_protocol = 0;
    unsigned short controlled_srcport = 0;
    unsigned short controlled_dstport = 0;
    unsigned int controlled_saddr = 0;
    unsigned int controlled_daddr = 0;
    unsigned int controlled_time_flag = 0;
    unsigned int controlled_time_begin = 0;
    unsigned int controlled_time_end = 0;

    //协议
    if (strncmp(ruleString.protocol.toStdString().data(), "icmp",4) == 0 )
        controlled_protocol = 1;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "tcp",3) == 0  )
        controlled_protocol = 6;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "udp",3) == 0 )
        controlled_protocol = 17;
    else if (strncmp( ruleString.protocol.toStdString().data(), "any",3) == 0 )
        controlled_protocol = 0;
    else {
        printf("Unkonwn protocol! please check and try again! \n");
        return false;
         }

    //源地址
    if (strncmp(ruleString.src_addr.toStdString().data(),"any",3) == 0)
        controlled_saddr = 0;
    else if ( inet_aton(ruleString.src_addr.toStdString().data(), (struct in_addr* )&controlled_saddr) == 0){
        printf("Invalid source ip address! please check and try again! \n ");
        return false;
    }

    //目的地址
    if (strncmp(ruleString.dst_addr.toStdString().data(),"any",3) == 0)
        controlled_daddr = 0;
    else if ( inet_aton(ruleString.dst_addr.toStdString().data(), (struct in_addr* )&controlled_daddr) == 0){
        printf("Invalid destination ip address! please check and try again! \n ");
        return false;
    }

    //源端口
    unsigned short tmpport;
    if (strncmp(ruleString.src_port.toStdString().data(),"any",3) == 0)
        controlled_srcport = 0;
    else {
        tmpport = atoi(ruleString.src_port.toStdString().data());
        if (tmpport == 0){
            printf("Invalid source port! please check and try again! \n ");
            return false;
        }
        controlled_srcport = htons(tmpport);
    }

    //目的端口
    if (strncmp(ruleString.dst_port.toStdString().data(),"any",3) == 0)
        controlled_dstport = 0;
    else {
        tmpport = atoi(ruleString.dst_port.toStdString().data());
        if (tmpport == 0){
            printf("Invalid dst port! please check and try again! \n ");
            return false;
        }
        controlled_dstport = htons(tmpport);
    }

    //Time_Flag
    if (strncmp(ruleString.time_flag.toStdString().data(), "yes",3) == 0 )
        controlled_time_flag = 1;
    else if ( strncmp(ruleString.time_flag.toStdString().data(), "no",2) == 0  )
        controlled_time_flag = 0;
    else {
        printf("Time Flag Wrong! \n");
        return false;
         }

    //Time_Begin
    controlled_time_begin = ruleString.hour_begin.toInt()*60 + ruleString.min_begin.toInt();
    //Time_End
    controlled_time_end = ruleString.hour_end.toInt()*60 + ruleString.min_end.toInt();

    //放入字符串中
    *(int *)p_controlinfo = controlled_protocol;
    *(int *)(p_controlinfo + 4) = controlled_saddr;
    *(int *)(p_controlinfo + 8) = controlled_daddr;
    *(int *)(p_controlinfo + 12) = controlled_srcport;
    *(int *)(p_controlinfo + 16) = controlled_dstport;
    *(int *)(p_controlinfo + 20) = controlled_time_flag;
    *(int *)(p_controlinfo + 24) = controlled_time_begin;
    *(int *)(p_controlinfo + 28) = controlled_time_end;

    return true;
}

bool ruleAddrCheck(QString addrString)
{
    //check ip
    QRegExp ip_reg("^([1-9]?\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "([1-9]?\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "([1-9]?\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\."
                   "([1-9]?\\d|1\\d\\d|2[0-4]\\d|25[0-5])$");
    if (addrString == "any"){
        return true;
    } else{
        QStringList addrStringSpilt = addrString.split("/");
        //mask
        if (addrStringSpilt.length() == 2){
            bool ok;
            int mask = addrStringSpilt[1].toInt(&ok);
            if (!ok || mask < 0 || mask > 32){
                return false;
            }
        } else if (addrStringSpilt.length() != 1){
            return false;
        }
        //addr
        if (!ip_reg.exactMatch(addrStringSpilt[0])){
            return false;
        }
    }
    return true;
}

bool rulePortCheck(QString portString)
{
    if (portString == "any"){
        return true;
    } else{
        bool ok;
        int port = portString.toInt(&ok);
        if (!ok || port < 0 || port > 65535){
            return false;
        }
    }
    return true;
}
