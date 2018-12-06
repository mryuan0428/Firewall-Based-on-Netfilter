#!/bin/sh
LOG=$(echo 'change' | sudo -p '' -S dmesg -c | grep '<WJ>')
echo "$LOG"
