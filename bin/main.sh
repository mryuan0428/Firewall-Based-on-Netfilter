#!/bin/sh

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE-$0}")"; pwd)

case "$1" in
    "insmod")
        result=$(pkexec bash $CUR_DIR/insmod.sh)
        ;;
    "rmmod")
        result=$(pkexec bash $CUR_DIR/rmmod.sh)
        ;;
    "ckmod")
        result=$(bash $CUR_DIR/ckmod.sh)
        ;;
    *)
        result="error command"
esac

echo -n "$result"
