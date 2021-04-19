#!/bin/bash
make re
ARG="";
./push_swap $ARG 2> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="0";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="NULL";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483647 -2147483648";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483648 -2147483649";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483647 -2147483648 -0.009";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483647 -2147483648 -18 59 0 0.3";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483647 -2147483648 -18 59 0 0 3 \n";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
ARG="2147483647 -2147483648 char -18 59 0 0 3";
./push_swap $ARG 2>> rendu.txt
./checker $ARG 2>> rendu.txt
if diff -q rendu.txt answer.txt > /dev/null
then
  echo "\0033[1;32m[success]\0033[0m"
else
  echo "\0033[1;31m[error]\0033[0m"
fi