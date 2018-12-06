#!/bin/sh

MOD_NAME="WJ_firewall"

if [ "$(lsmod | grep -c "$MOD_NAME")" == "1" ]
then
    echo "true"
else
    echo "false"
fi

