#!/bin/bash

architecture=$(uname -a)
pcpu=cat /proc/cpuinfo | grep "physical id" | wc -l
vcpu=cat /proc/cpuinfo | grep processor | wc -l
mem_tot=free --mega | awk '/Mem:/ {print $2}'
mem_use=free --mega | awk '/Mem:/ {print $3}'
mem_perc=$((100*$mem_use/$mem_tot))
dsk_use=df -Bm | awk '// {print $3}' | tr -d M
dsk_tot=df -Bg | awk '// {print $2}' | tr -d G
dsk_perc=df | awk '// {print $5}'
cpu_load=top -n 1 -b | awk '/^%Cpu/{print 100-$8"%"}'
lst_boot=who -b | awk '{print $3,$4}'
lvm=
tcp=netstat -s | grep "connections established" | awk '{print $1}'
usr_log=w | awk '/ user/ {print $6}'
net=
sudo=

wall "#Architecture: $architecture
#CPU physical : $p_cpu
#vCPU : $vcpu
#Memory Usage: $mem_use/$mem_tot MB ($mem_perc%)
#Disk Usage: $dsk_use/$dsk_tot Gb ($dsk_perc)
#CPU load: $cpu_load
#Last boot: $lst_boot
#LVM use: $lvm
#connexions TCP : $tcp ESTABLISHED
#User log: $usr_log
#Network: $net
#Sudo : $sudo"
