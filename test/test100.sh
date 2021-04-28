#!/bin/bash
ARG=`./genstack.pl 100 -1000 1000` ;
echo "TEST 1 : "
bash key_press.sh
./../push_swap $ARG | ./../checker -v $ARG
RES=$(./../push_swap $ARG | wc -l)
if ((RES < 850))
then
	echo "\0033[1;32mTest 1 : $RES		[success]\0033[0m"
else
	echo "\0033[1;31mTest 1 : $RES 		[error]\0033[0m"
fi