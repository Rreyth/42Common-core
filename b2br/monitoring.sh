#!/bin/bash

time_log=$(who | tail -c 2)
time_act=$(timedatectl | grep Local | tail -c 9 | cut -b 1)
if [ $time_log -eq $time_act ]
then
architecture=$(uname -a)
pcpu=$(cat /proc/cpuinfo | grep "physical id" | wc -l)
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
mem_tot=$(free --mega | awk '/Mem:/ {print $2}')
mem_use=$(free --mega | awk '/Mem:/ {print $3}')
mem_perc=$((100*$mem_use/$mem_tot))
dsk_use=$(df -h --total | awk '/total/ {print $3}')
dsk_tot=$(df -h --total | awk '/total/ {print $2}')
dsk_perc=$(df -h --total | awk '/total/ {print $5}')
cpu_load=$(top -n 1 -b | awk '/^%Cpu/{print 100-$8"%"}')
lst_boot=$(who -b | awk '{print $3,$4}')
lvm_c=$(lsblk | grep lvm | wc -l)
lvm_use=$(if [ $lvm_c -ne 0 ]; then echo yes; else echo no; fi)
tcp=$(netstat -s | awk '/established/ {print $1}')
usr_log=$(who | wc -l)
ip=$(hostname -I)
mac=$(ip link show | awk '/ether/ {print $2}')
sudo=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

wall "#Architecture: $architecture
#CPU physical : $pcpu
#vCPU : $vcpu
#Memory Usage: $mem_use/$mem_tot MB ($mem_perc%)
#Disk Usage: $dsk_use/$dsk_tot ($dsk_perc)
#CPU load: $cpu_load
#Last boot: $lst_boot
#LVM use: $lvm_use
#Connexions TCP : $tcp ESTABLISHED
#User log: $usr_log
#Network: $ip ($mac)
#Sudo : $sudo cmd"
fi
