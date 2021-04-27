#!/bin/bash
cd ../
make re
cd test
ARG="";
./../checker $ARG 2> rendu.txt 1>> rendu.txt
ARG="NULL";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="2147483648 -2147483649";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="2147483647 -2147483648 -0.009";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="2147483647 -2147483648 -18 59 0 0.3";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="2147483647 -2147483648 -18 59 0 0 3 \n";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="2147483647 -2147483648 char -18 59 0 3";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="3 2 1 5 0-184";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="3 -2 1 5 0  -2 3";
./../checker $ARG 2>> rendu.txt 1>> rendu.txt
ARG="";
./../push_swap $ARG 2>> rendu.txt 
ARG="\0";
./../push_swap $ARG 2>> rendu.txt 
ARG="NULL";
./../push_swap $ARG 2>> rendu.txt 
ARG="2147483648 -2147483649";
./../push_swap $ARG 2>> rendu.txt 
ARG="2147483647 -2147483648 -0.009";
./../push_swap $ARG 2>> rendu.txt 
ARG="2147483647 -2147483648 -18 59 0 0.3";
./../push_swap $ARG 2>> rendu.txt 
ARG="2147483647 -2147483648 -18 59 0 0 3 \n";
./../push_swap $ARG 2>> rendu.txt 
ARG="2147483647 -2147483648 char -18 59 0 3";
./../push_swap $ARG 2>> rendu.txt 
ARG="3 2 1 0\nrra\npb\nsa\nrra\npa";
./../push_swap $ARG 2>> rendu.txt 
ARG="3 2 1 5 0\nrra\npb\nsa\nrra\npa";
./../push_swap $ARG 2>> rendu.txt 
ARG="3 -2 1 5 0  -2\nrra\npb\nsa\nrra\npa";
./../push_swap $ARG 2>> rendu.txt
ARG="1 3 one";
./../push_swap $ARG 2>> rendu.txt | ./../checker $ARG 2>> rendu.txt
if diff -q rendu.txt answer.txt > /dev/null
then
  echo "\0033[1;32mCheck error : 			[success]\0033[0m"
else
  echo "\0033[1;31mCheck error : 			[error]\0033[0m"
fi
diff  rendu.txt answer.txt |grep -m1 ""
sh test.sh
sh test3.sh
sh test21.sh
