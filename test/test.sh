#!/bin/bash
OK="OK";

echo ""
ARG="0 1 2 3 4 5 6 7 8 9";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 1 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 1 : $RES\0033[0m"
fi

ARG="9 8 7 6 5 4 3 2 1 0";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 2 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 2 : $RES\0033[0m"
fi

ARG="-987 26 0 -3 45 9 6 2 18 5";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 3 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 3 : $RES\0033[0m"
fi

ARG="7 88";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 4 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 4 : $RES\0033[0m"
fi

ARG="-5698 45 12 4 5 3 0 78 54 2";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 5 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 5 : $RES\0033[0m"
fi

ARG="-9 -6 -5 -78 -45 -23 -0 -98 -7 -8";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 6 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 6 : $RES\0033[0m"
fi

ARG="4 213 8 453 -98 -23 -7 25 55 27 1";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 7 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 7 : $RES\0033[0m"
fi


ARG="-1000000  5432 128 9 1 -68 24564 5 -24 2";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 8 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 8 : $RES\0033[0m"
fi

ARG=" 789 26 98 1293 78 984 23 123 -0";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 9 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 9 : $RES\0033[0m"
fi

ARG="789 456 213 654 987321 321 03261 36 942 -5 -7 8";
RES=$(./../push_swap $ARG | ./../checker $ARG)
if echo "$RES" | grep "$OK" >/dev/null 2>&1;
then
	echo "\0033[1;32mTest 10 : $RES\0033[0m"
else
	echo "\0033[1;31mTest 10 : $RES\0033[0m"
fi
