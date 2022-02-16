#!/bin/bash
make
clear
while true
do 
    ARG=`./Random-numbers-generator/a.out $1 -2147483648 2147483647`
    #echo $ARG
    #./push_swap $ARG
    ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./checker_linux $ARG    
    #sleep 0.4
done