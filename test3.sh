#!/bin/bash
typeset -i RES
ARG="1 2 3";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 1 : $RES		[success]\0033[0m"
else
	echo "\0033[1;31mTest 1 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG > test/rendu.txt
ARG="2 1 3";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 2 : $RES 		[success]\0033[0m"
else
	echo "\0033[1;31mTest 2 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
ARG="1 3 2";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 3 : $RES 		[success]\0033[0m"
else
	echo "\0033[1;31mTest 3 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
ARG="2 3 1";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 4 : $RES 		[success]\0033[0m"
else
	echo "\0033[1;31mTest 4 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
ARG="3 2 1";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 5 : $RES 		[success]\0033[0m"
else
	echo "\0033[1;31mTest 5 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
ARG="3 1 2";
RES=$(./push_swap $ARG | wc -l)
if ((RES < 4))
then
	echo "\0033[1;32mTest 6 : $RES 		[success]\0033[0m"
else
	echo "\0033[1;31mTest 6 : $RES 		[error]\0033[0m"
fi
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
if diff -q test/rendu.txt test/answer_3.txt > /dev/null
then
  echo "\0033[1;32mCheck 3 :		 		[success]\0033[0m"
else
  echo "\0033[1;31mCheck 3 :	 			[error]\0033[0m"
fi
diff  test/rendu.txt test/answer_3.txt | grep -m1 ""
