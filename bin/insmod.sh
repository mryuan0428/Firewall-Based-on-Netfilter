#!/bin/sh

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE-$0}")"; pwd)
MOD_NAME="WJ_firewall.ko"
DEV_PATH="/dev/controlinfo"

if [ "$(bash $CUR_DIR/ckmod.sh)" == "true" ]
then
    echo "success"
elif [ "$(which pkexec)" == "" ]
then
    echo "pkexec"
else
    insmod $CUR_DIR/$MOD_NAME
    if [ "$?" == "0" ]
    then
        mknod ${DEV_PATH} c 124 0
        chmod 0666 ${DEV_PATH}
        echo "success"
    else
        echo "failure"
    fi
fi
