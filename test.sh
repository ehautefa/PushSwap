#!/bin/bash
make re
# ARG="";
# ./push_swap $ARG 2> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="0";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="NULL";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483647 -2147483648";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483648 -2147483649";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483647 -2147483648 -0.009";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483647 -2147483648 -18 59 0 0.3";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483647 -2147483648 -18 59 0 0 3 \n";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="2147483647 -2147483648 char -18 59 0 0 3";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
# ARG="3 2 1 0\nrra\npb\nsa\nrra\npa";
# ./push_swap $ARG 2>> test/rendu.txt
# ./checker $ARG 2>> test/rendu.txt
ARG="3 2 1 5 5\nrra\npb\nsa\nrra\npa";
# ./push_swap $ARG 2>> test/rendu.txt
./checker $ARG 2> test/rendu.txt
# if diff -q test/rendu.txt test/answer.txt > /dev/null
# then
#   echo "\0033[1;32m[success]\0033[0m"
# else
#   echo "\0033[1;31m[error]\0033[0m"
# fi