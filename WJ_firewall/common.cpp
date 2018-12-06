#include "common.h"

QList<rule_str_tp> ruleStringList;

bool ruleFromString(rule_str_tp ruleString, rule_tp &rule)
{
    //action
    if (ruleString.action == "permit"){
        rule.flag &= 0xFF ^ BYTE0;
    } else if (ruleString.action == "reject"){
        rule.flag |= BYTE0;
    } else{
        return false;
    }

    //time
    if (ruleString.time == "any"){
        rule.flag &= 0xFF ^ BYTE1;
    } else{
        rule.flag |= BYTE1;
         if (ruleString.time == "work"){
             rule.days = BYTE1 | BYTE2 | BYTE3 | BYTE4 | BYTE5;
             rule.bg_time = 8 * 60;     //8:00
             rule.ed_time = 18 * 60;    //18:00
         } else{
             return false;
         }
    }

    //protocol
    if (ruleString.protocol == "any"){
        rule.flag &= 0xFF ^ BYTE2;
    } else{
        rule.flag |= BYTE2;
        if (ruleString.protocol == "tcp"){
            rule.protocol = IPPROTO_TCP;
        } else if (ruleString.protocol == "udp"){
            rule.protocol = IPPROTO_UDP;
        } else if (ruleString.protocol == "icmp"){
            rule.protocol = IPPROTO_ICMP;
        }else{
            return false;
        }
    }

    //log
    if (ruleString.log == "no"){
        rule.flag &= 0xFF ^ BYTE3;
    } else if (ruleString.log == "yes"){
        rule.flag |= BYTE3;
    } else{
        return false;
    }

    //src_port
    if (ruleString.src_port == "any"){
        rule.flag &= 0xFF ^ BYTE4;
    } else if(rulePortCheck(ruleString.src_port)){
        rule.flag |= BYTE4;
        int src_port_int = ruleString.src_port.toInt();
        rule.src_port = htons((quint16)src_port_int);
    } else{
        return false;
    }

    //dst_port
    if (ruleString.src_port == "any"){
        rule.flag &= 0xFF ^ BYTE5;
    } else if(rulePortCheck(ruleString.dst_port)){
        rule.flag |= BYTE5;
        int dst_port_int = ruleString.dst_port.toInt();
        rule.dst_port = htons((quint16)dst_port_int);
    } else{
        return false;
    }

    //src_ip
    if (ruleString.src_addr == "any"){
        rule.flag &= 0xFF ^ BYTE6;
    } else if (ruleAddrCheck(ruleString.src_addr)){
        rule.flag |= BYTE6;
        QStringList src_ip_spilt = ruleString.src_addr.split("/");
        //mask
        if (src_ip_spilt.length() == 1){
            rule.src_mask = 0xFFFFFFFF;
        } else if (src_ip_spilt.length() == 2){
            int mask = src_ip_spilt[1].toInt();
            rule.src_mask = htonl(0xFFFFFFFF << (32 - mask));
        }
        //addr
        struct in_addr src_in_addr;
        const char *src_ip_str = src_ip_spilt[0].toUtf8().constData();
        inet_aton(src_ip_str, &src_in_addr);
        rule.src_addr = src_in_addr.s_addr;
    } else{
        return false;
    }

    //dst_ip
    if (ruleString.dst_addr == "any"){
        rule.flag &= 0xFF ^ BYTE7;
    } else if (ruleAddrCheck(ruleString.dst_addr)){
        rule.flag |= BYTE7;
        QStringList dst_ip_spilt = ruleString.dst_addr.split("/");
        //mask
        if (dst_ip_spilt.length() == 1){
            rule.dst_mask = 0xFFFFFFFF;
        } else if (dst_ip_spilt.length() == 2){
            int mask = dst_ip_spilt[1].toInt();
            rule.dst_mask = htonl(0xFFFFFFFF << (32 - mask));
        }
        //addr
        struct in_addr dst_in_addr;
        const char *dst_ip_str = dst_ip_spilt[0].toUtf8().constData();
        inet_aton(dst_ip_str, &dst_in_addr);
        rule.dst_addr = dst_in_addr.s_addr;
    } else{
        return false;
    }

    return true;
}


bool ruleFromString_new(rule_str_tp ruleString, char *p_controlinfo)
{
    unsigned int controlled_protocol = 0;
    unsigned short controlled_srcport = 0;
    unsigned short controlled_dstport = 0;
    unsigned int controlled_saddr = 0;
    unsigned int controlled_daddr = 0;

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

    *(int *)p_controlinfo = controlled_protocol;
    *(int *)(p_controlinfo + 4) = controlled_saddr;
    *(int *)(p_controlinfo + 8) = controlled_daddr;
    *(int *)(p_controlinfo + 12) = controlled_srcport;
    *(int *)(p_controlinfo + 16) = controlled_dstport;

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
