 - 开发环境：
	 - 操作系统：Ubuntu 15.10
	 - 内核版本：4.2.0-16-generic 
	 - 开发软件：Qt 5.9.0
	 - 编译器：gcc version 5.2.1

 - 项目内容：
```
    |--WJ_firewall文件夹（应用层：使用Qt开发的用户界面）
    	|--……

    |--build-WJ_firewall-Desktop_Qt_5_9_0_GCC_64bit-Debug文件夹（Qt编译产生的可执行程序，sudo ./WJ_firewall 可运行）
        |--WJ_firewall（可执行程序）
        |--……

    |--my_mod文件夹（内核模块代码：在NF_INET_POST_ROUTING结点挂在钩子函数，接收规则并过滤报文）
    	|--WJ_firewall.c
        |--Makefile（sudo make 编译得到内核模块WJ_firewall.ko，并自动复制到bin文件夹）

    |--bin文件夹
        |--main.sh（在应用层代码中被调用，通过调用其他shell脚本进行内核模块的插入、检查、移除和报文过滤日志的采集）
        |--insmod.sh（内核模块插入）
        |--ckmod.sh（检查内核模块是否插入）
        |--rmmod.sh（内核模块移除）
        |--log.sh（报文过滤日志的采集）
    |--data文件夹
        |--rule.txt（保存正在运行的过滤规则）
        |--log.txt（保存报文过滤日志记录）
        |--rule_new（待导入的过滤规则，格式：SrcIP%DstIP%SPort%DPort%Time_Flag%Start_Hour%Start_Min%Stop_Hour%Stop_Min%Protocol）
        |--rule_out(导出的过滤规则)
    |--doc文件夹（项目开发文档）
```

 - 说明：
```
 - 防火墙为黑名单模式，符合规则之一报文即被Reject
 - 对于所有被Reject的报文都自动进行日志记录
```
