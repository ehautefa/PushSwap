echo 0
ARG="0 1 2 3 4 5 6 7 8 9";
./push_swap $ARG | ./checker $ARG > test/rendu.txt
echo 1
ARG="9 8 7 6 5 4 3 2 1 0";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 2
ARG="-987 26 0 -3 45 9 6 2 18 5";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 3
ARG="7 88";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 4
ARG="-5698 45 12 4 5 3 0 78 54 2";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 5
ARG="-9 -6 -5 -78 -45 -23 -0 -98 -7 -8";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 6
ARG="4 213 8 453 -98 -23 -7 25 55 27 1";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 7
ARG="-1000000  5432 128 9 1 -68 24564 5 -24 2";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 8
ARG=" 789 26 98 1293 78 984 23 123 -0";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
echo 9
ARG="789 456 213 654 987321 321 03261 36 942 -5 -7 8";
./push_swap $ARG | ./checker $ARG >> test/rendu.txt
if diff -q test/rendu.txt test/answer_2.txt > /dev/null
then
  echo "\0033[1;32mCheck 10 : 			[success]\0033[0m"
else
  echo "\0033[1;31mCheck 10 : 			[error]\0033[0m"
fi
diff  test/rendu.txt test/answer_2.txt 
