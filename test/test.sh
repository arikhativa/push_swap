#!/bin/bash

EXEC=push_swap
CHECKER=checker_Mac

RES_DIR=./test/resource

FILES=($RES_DIR/one_num_no_action $RES_DIR/two_num_no_action $RES_DIR/10 $RES_DIR/7 $RES_DIR/100 $RES_DIR/500 $RES_DIR/5)

# add test for 5 buy 12

i=0
while [ $i -ne ${#FILES[@]} ]
do
	ARGS=$(cat ${FILES[i]})
	./$EXEC $ARGS | ./$CHECKER $ARGS
	i=$((i+1))
done

printf "\none\n"
./$EXEC 1 | ./$CHECKER 1

printf "\ntwo\n"
./$EXEC 1 2 | ./$CHECKER 1 2
./$EXEC 2 1 | ./$CHECKER 2 1

printf "\nthree\n"
./$EXEC 1 2 3 | ./$CHECKER 1 2 3 
./$EXEC 2 1 3 | ./$CHECKER 2 1 3 
./$EXEC 1 3 2 | ./$CHECKER 1 3 2 
./$EXEC 3 1 2 | ./$CHECKER 3 1 2 
./$EXEC 2 3 1 | ./$CHECKER 2 3 1 
./$EXEC 3 2 1 | ./$CHECKER 3 2 1 

printf "\nfour\n"
./$EXEC 4 1 2 3 | ./$CHECKER 4 1 2 3 
./$EXEC 2 4 1 3 | ./$CHECKER 2 4 1 3 
./$EXEC 1 3 2 4 | ./$CHECKER 1 3 2 4 
./$EXEC 3 1 4 2 | ./$CHECKER 3 1 4 2 
./$EXEC 4 2 3 1 | ./$CHECKER 4 2 3 1 
./$EXEC 4 3 2 1 | ./$CHECKER 4 3 2 1 

printf "\nlimits\n"
# smallest
./$EXEC -2147483648 | ./$CHECKER -2147483648
# lagestest
./$EXEC 2147483647 | ./$CHECKER 2147483647
