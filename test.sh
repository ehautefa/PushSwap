make re
ARG="";
./push_swap $ARG | diff - ""
./checker $ARG
# ARG="0";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="NULL";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483647 -2147483648";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483648 -2147483649";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483647 -2147483648 -0.009";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483647 -2147483648 -18 59 0 0.3";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483647 -2147483648 -18 59 0 0 3 \n";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG
# ARG="2147483647 -2147483648 -18 char 59 0 0 3";
# ./push_swap $ARG
# ./push_swap $ARG | ./checker $ARG