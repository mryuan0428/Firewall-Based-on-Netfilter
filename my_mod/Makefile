obj-m += WJ_firewall.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)
MOD_NAME := "WJ_firewall.ko"

default:
	#gcc -o WJ_firewall.o WJ_firewall.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	cp $(MOD_NAME) "../bin/"
