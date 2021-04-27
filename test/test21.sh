#!/bin/bash
OK="OK";

ARG="17 9 21 20 22 8 14 12 2 15 23 7 11 6 0 13 24 10 5 16 19 18 1 4 25 3";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 1 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 1 : $RES\0033[0m"
fi

ARG="21 2 8 14 18 1 16 0 22 23 7 9 6 20 19 3 12 4 13 5 17 11 15 24 10";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 2 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 2 : $RES\0033[0m"
fi

ARG="1 13 4 19 20 3 8 22 9 21 11 0 17 23 18 6 10 16 15 14 5 7 2 12";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 3 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 3 : $RES\0033[0m"
fi

ARG="14 2 1 22 11 8 9 17 19 0 10 3 20 4 21 16 18 5 12 7 15 13 6";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 4 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 4 : $RES\0033[0m"
fi

ARG="5 16 -6 2 20 12 10 15 19 7 14 11 9 8 18 1 13 4 17 0 3 25";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 5 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 5 : $RES\0033[0m"
fi
