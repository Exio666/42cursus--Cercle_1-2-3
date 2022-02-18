#!/bin/bash
make -C ..
make -C .. bonus
gcc generator.c -o generateur
clear
echo "generateur du github de charlesjullien"
while true
do 
	ARG=`./generateur $1 -2147483648 2147483647`
	echo $ARG
	#../push_swap $ARG
	../push_swap $ARG | wc -l
	#../push_swap $ARG | ../checker_linux $ARG 
	../push_swap $ARG | ../checker $ARG
	#sleep 0.1
done