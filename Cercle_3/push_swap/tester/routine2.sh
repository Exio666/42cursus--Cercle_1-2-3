#!/bin/bash
make -C .. re
clear
echo "generateur du github de charlesjullien"
while true
do 
    ARG=`generateur $1 -2147483648 2147483647`
    #echo $ARG
    #../push_swap $ARG
    ../push_swap $ARG | wc -l
    ../push_swap $ARG | ./checker_linux $ARG    
    #sleep 0.4
done