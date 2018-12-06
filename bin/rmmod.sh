#!/bin/sh

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE-$0}")"; pwd)
MOD_NAME="WJ_firewall"
DEV_PATH="/dev/controlinfo"

if [ "$(bash $CUR_DIR/ckmod.sh)" == "false" ]
then
    echo "success"
elif [ "$(which pkexec)" == "" ]
then
    echo "pkexec"
else
    rm ${DEV_PATH}
    rmmod $MOD_NAME
    if [ "$?" == "0" ]
    then
        echo "success"
    else
        echo "failure"
    fi
fi
