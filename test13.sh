ARG="0 1 2 3 4 5 6 7 8 9 10 11 12 13";
echo "TEST 1 : "
./push_swap $ARG | ./checker $ARG
ARG="13 12 11 10 9 8 7 6 5 4 3 2 1 0";
echo "TEST 2 : "
./push_swap $ARG | ./checker $ARG 
ARG="-987 26 0 -3 45 9 6 2 18 5 -82 654 3246";
echo "TEST 3 : "
./push_swap $ARG | ./checker $ARG 
ARG="7 88 4 879 231 56248 4687123 467843212 45487 38 11 689 548";
echo "TEST 4 : "
./push_swap $ARG | ./checker $ARG 
ARG="-5698 45 12 4 5 3 0 78 54 2 -784 659 33212 787";
echo "TEST 5 : "
./push_swap $ARG | ./checker $ARG 
ARG="-9 -6 -5 -78 -45 -23 -0 -98 -7 -8";
echo "TEST 6 : "
./push_swap $ARG | ./checker $ARG 
ARG="4 213 8 453 -98 -23 -7 25 55 27 1";
echo "TEST 7 : "
./push_swap $ARG | ./checker $ARG 
ARG="-1000000  5432 128 9 1 -68 24564 5 -24 2";
echo "TEST 8 : "
./push_swap $ARG | ./checker $ARG 
ARG=" 789 26 98 1293 78 984 23 123 -0";
echo "TEST 9 : "
./push_swap $ARG | ./checker $ARG 
ARG="789 456 213 654 987321 321 03261 36 942 -5 -7 8";
echo "TEST 10 : "
./push_swap $ARG | ./checker $ARG 