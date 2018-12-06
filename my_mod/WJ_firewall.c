//#define __KERNEL__
//#define MODULE

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/if_ether.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/tcp.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <linux/udp.h>
#include <linux/time.h>
#include <linux/timex.h>
#include <linux/rtc.h>

#define MATCH	1
#define NMATCH	0

struct nf_hook_ops myhook;

//保存正在使用规则的信息
unsigned int controlled_protocol = 0;
unsigned short controlled_srcport = 0;
unsigned short controlled_dstport = 0;
unsigned int controlled_saddr = 0;
unsigned int controlled_daddr = 0;

unsigned int controlled_time_flag = 0;
unsigned int controlled_time_begin = 0;
unsigned int controlled_time_end = 0;

//正在处理数据包信息转化为字符串用于日志输出
char ip_buff_src[16];
char ip_buff_dst[16];
char port_buff_src[10];
char port_buff_dst[10];
char time_buff[50];
char protocol_buff[10];

char controlinfo[1600]; //存储多条规则，每条32byte
char *pchar;
int num = 0; //规则条数

struct sk_buff *tmpskb;
struct iphdr *piphdr;

char * addr_from_net(char * buff, __be32 addr)
{
    __u8 *p = (__u8*)&addr;
    snprintf(buff, 16, "%u.%u.%u.%u",
        (__u32)p[0], (__u32)p[1], (__u32)p[2], (__u32)p[3]);
    return buff;
}

char * time_from_tm(char * buff, struct rtc_time *tm)
{
    snprintf(buff, 50, "%04d/%02d/%02d %02d:%02d:%02d",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);
    return buff;
}

bool cktime(struct rtc_time *tm) //1不运行
{
	if(controlled_time_flag == 0){ //Time_Flag关闭，直接判断下一条规则
		return 0;
		}
	if(controlled_time_flag == 1){ //Time_Flag开启，判断时间区间
		if(((tm->tm_hour*60+tm->tm_min)<controlled_time_begin)||((tm->tm_hour*60+tm->tm_min)>controlled_time_end)){
			return 1;
		}
		else return 0;
	}
	return 0;
}

bool port_check(unsigned short srcport, unsigned short dstport){
	if ((controlled_srcport == 0 ) && ( controlled_dstport == 0 ))
		return MATCH;
	if ((controlled_srcport != 0 ) && ( controlled_dstport == 0 ))
	{
		if (controlled_srcport == srcport) 
			return MATCH;
		else
			return NMATCH;
	}
	if ((controlled_srcport == 0 ) && ( controlled_dstport != 0 ))
	{
		if (controlled_dstport == dstport) 
			return MATCH;
		else
			return NMATCH;
	}
	if ((controlled_srcport != 0 ) && ( controlled_dstport != 0 ))
	{
		if ((controlled_srcport == srcport) && (controlled_dstport == dstport)) 
			return MATCH;
		else
			return NMATCH;
	}
	return NMATCH;
}

bool ipaddr_check(unsigned int saddr, unsigned int daddr){
	if ((controlled_saddr == 0 ) && ( controlled_daddr == 0 ))
		return MATCH;
	if ((controlled_saddr != 0 ) && ( controlled_daddr == 0 ))
	{
		if (controlled_saddr == saddr) 
			return MATCH;
		else
			return NMATCH;
	}
	if ((controlled_saddr == 0 ) && ( controlled_daddr != 0 ))
	{
		if (controlled_daddr == daddr) 
			return MATCH;
		else
			return NMATCH;
	}
	if ((controlled_saddr != 0 ) && ( controlled_daddr != 0 ))
	{
		if ((controlled_saddr == saddr) && (controlled_daddr == daddr)) 
			return MATCH;
		else
			return NMATCH;
	}
	return NMATCH;
}

bool icmp_check(void){
	struct icmphdr *picmphdr;
	//printk("<0>This is an ICMP packet.\n");
	picmphdr = (struct icmphdr *)(tmpskb->data +(piphdr->ihl*4));

	if (picmphdr->type == 0){
			if (ipaddr_check(piphdr->daddr,piphdr->saddr) == MATCH){
			 	printk("An ICMP packet is denied! \n");
				return 1;
			}
	}
	if (picmphdr->type == 8){
			if (ipaddr_check(piphdr->saddr,piphdr->daddr) == MATCH){
			 	printk("An ICMP packet is denied! \n");
				return 1;
			}
	}
    return 0;
}

bool tcp_check(void){
	struct tcphdr *ptcphdr;
	//   printk("<0>This is an tcp packet.\n");
	ptcphdr = (struct tcphdr *)(tmpskb->data +(piphdr->ihl*4));
	if ((ipaddr_check(piphdr->saddr,piphdr->daddr) == MATCH) && (port_check(ptcphdr->source,ptcphdr->dest) == MATCH)){
	 	printk("A TCP packet is denied! \n");
	 	snprintf(port_buff_src, 10, ":%d", ntohs(ptcphdr->source));
        snprintf(port_buff_dst, 10, ":%d", ntohs(ptcphdr->dest));
		return 1;
	}
	else
      return 0;
}

bool udp_check(void){
	struct udphdr *pudphdr;	
	//   printk("<0>This is an udp packet.\n");
	pudphdr = (struct udphdr *)(tmpskb->data +(piphdr->ihl*4));
	if ((ipaddr_check(piphdr->saddr,piphdr->daddr) == MATCH) && (port_check(pudphdr->source,pudphdr->dest) == MATCH)){
	 	snprintf(port_buff_src, 10, ":%d", ntohs(pudphdr->source));
        snprintf(port_buff_dst, 10, ":%d", ntohs(pudphdr->dest));
	 	printk("A UDP packet is denied! \n");
		return 1;
	}
	else
      return 0;
}

/*unsigned int hook_func(unsigned int hooknum,struct sk_buff **skb,const struct net_device *in,const struct net_device *out,int (*okfn)(struct sk_buff *))
*/
unsigned int hook_func(void * priv,struct sk_buff *skb,const struct nf_hook_state * state){

	bool result = 0;
	struct timex txc;
	struct rtc_time tm;

   	tmpskb = skb;
	piphdr = ip_hdr(tmpskb);

	//时间
	do_gettimeofday(&txc.time);   //获取当前UTC时间
    txc.time.tv_sec += 8 * 60 * 60;  //把UTC时间调整为本地时间
    rtc_time_to_tm(txc.time.tv_sec, &tm);   //算出时间中的年月日等数值到tm中
	time_from_tm(time_buff, &tm);

	addr_from_net(ip_buff_src, piphdr->saddr);
	addr_from_net(ip_buff_dst, piphdr->daddr);


	if(num == 0) return NF_ACCEPT; 
	else {
		int i;
		pchar = controlinfo;
		for (i = 0; i<num; i++){
			//One rule
			controlled_protocol = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_saddr = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_daddr = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_srcport = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_dstport = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_time_flag = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_time_begin = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_time_end = *(( int *) pchar);
			pchar = pchar + 4;

			//判断该条规则是否在运行时间中，1:不在运行时间中；0:无flag或在运行时间中
			if(cktime(&tm) == 1){
				continue;
			}

			if(piphdr->protocol != controlled_protocol) 
      			{ result = 0; continue; }
			else{
      			if (piphdr->protocol  == 1){ //ICMP packet
      				snprintf(protocol_buff, 10, "%s", "ICMP");
      				snprintf(port_buff_src, 10, " ");
        			snprintf(port_buff_dst, 10, " ");
      				result = icmp_check();
      			}  
				else if (piphdr->protocol  == 6){ //TCP packet
					snprintf(protocol_buff, 10, "%s", "TCP");
					result = tcp_check();
				} 
				else if (piphdr->protocol  == 17){ //UDP packet
					snprintf(protocol_buff, 10, "%s", "UDP");
					result = udp_check();
				}
				else
				{
					printk("Unkonwn type's packet! \n");
					return NF_ACCEPT;
				}

				//Judge
				if(result == 0) continue;
				else {
					printk("<WJ>%s  %s packet from  %s%s  to  %s%s  rejected by rule %d \n",
                        time_buff, protocol_buff, ip_buff_src, port_buff_src,
                        ip_buff_dst, port_buff_dst, i+1);
					return NF_DROP;
				}
      		}

		}
		return NF_ACCEPT;
	}

}

static ssize_t write_controlinfo(struct file * fd, const char __user *buf, size_t len, loff_t *ppos)
{
	
	if (len == 0){
		return len;
	}

	if (copy_from_user(controlinfo, buf, len) != 0){
		printk("Can't get the control rule! \n");
		printk("Something may be wrong, please check it! \n");
		return 0;
	}

	pchar = controlinfo;
	num = len/32;
	
	return len;
}


struct file_operations fops = {
	.owner=THIS_MODULE, 
	.write=write_controlinfo,
}; 


static int __init initmodule(void)
{
	int ret;
	printk("Init Module\n");
	myhook.hook=hook_func;
	myhook.hooknum=NF_INET_POST_ROUTING;
	myhook.pf=PF_INET;
	myhook.priority=NF_IP_PRI_FIRST;
	nf_register_hook(&myhook);
	ret = register_chrdev(124, "/dev/controlinfo", &fops); 	
	if (ret != 0) printk("Can't register device file! \n"); 

    	return 0;
}

static void __exit cleanupmodule(void)
{
	nf_unregister_hook(&myhook);
	unregister_chrdev(124, "controlinfo");	 
        printk("CleanUp\n");
}

module_init(initmodule);
module_exit(cleanupmodule);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("WJ_Yuan");
