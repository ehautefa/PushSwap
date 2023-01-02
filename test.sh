#!/bin/bash
make bonus
if [ $# -eq 0 ]
  then
    echo -e "\0033[1;31m Usage: ./test <stackSize>"
else
	ARG=`./test/genstack.pl $@ -1000 1000`;
	bash key_press.sh
	./push_swap $ARG | ./checker -v $ARG
	RES=$(./push_swap $ARG | wc -l)
	echo -e "\0033[1;32m$@ elements sorted with $RES instructions !\0033[0m"
fi