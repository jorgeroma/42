#!/bin/bash

GOD='\033[1;33m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
NC='\033[0m' # No Color

var2=$(echo "$GOD""Very Important Message From Your GOD:")
var3=$(echo "$BLUE""\t#Architecture:\t\t""$CYAN" `uname -a`)
var4=$(echo "$BLUE""\t#CPU physical:\t\t""$CYAN" `lscpu | egrep '^CPU\(s\):' | grep -Eo '[0-9]+'`)
var5=$(echo "$BLUE""\t#vCPU:\t\t\t""$CYAN" `cat /proc/cpuinfo | grep processor | wc -l`)
var6=$(echo "$BLUE""\tMemory Usage:\t\t""$CYAN" `free | awk '/Mem/{printf("%d/%dMB (%.2f%)"), $3/1000, $2/1000, $3/$2*100}'`)
var7=$(echo "$BLUE""\t#Disk Usage:\t\t""$CYAN" `df -Ph | sed s/%//g | egrep 'LVMGroup-home' | grep -Eo [0-9]+[\.[0-9]+]? | tr '\n' ' '| awk '{printf("%.1f/%.1fGB (%.2f%)"), $3, $1, (1-$3/$1)*100}'`)
var8=$(echo "$BLUE""\t#CPU load:\t\t""$CYAN" `cat /proc/stat | awk '/cpu/{printf("%.2f%\n"), ($2+$4)*100/($2+$4+$5)}' |  awk '{print $0}' | head -1`)
var9=$(echo "$BLUE""\t#Last boot:\t\t""$CYAN" `uptime -s`)
var10=$(echo "$BLUE""\t#LVM use:\t\t""$CYAN" `cat /etc/fstab | egrep '/dev/mapper' | wc -l | awk '{if ($0 > 0) printf("yes\n"); else printf("no\n");}'`)
var11=$(echo "$BLUE""\t#Connections TCP:\t""$CYAN" `netstat -ant | grep ESTABLISHED | wc -l` "ESTABLISHED")
var12=$(echo "$BLUE""\t#User log:\t\t""$CYAN" `users | wc -w`)
var13=$(echo "$BLUE""\t#Network:\t\t""$CYAN" `hostname -I` "("`ip link show | egrep 'link/ether' | grep -Eo '([0-9a-z]+:){5}[0-9a-z]{2}' | awk 'NR==1'`")")
var14=$(echo "$BLUE""\t#Sudo:\t\t\t""$CYAN" `journalctl _COMM=sudo | grep COMMAND | wc -l`"$NC")

wall -n "$var2
$var3
$var4
$var5
$var6
$var7
$var8
$var9
$var10
$var11
$var12
$var13
$var14"