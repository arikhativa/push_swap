#!/bin/bash

CHECKER=checker_linux
cat /etc/os-release > /dev/null 2>&1 
if [ $? -eq "1" ]
then
	CHECKER=checker_Mac
fi

EXEC=push_swap
RES_DIR=./test/resource
FILES=($RES_DIR/10 $RES_DIR/20 $RES_DIR/100 $RES_DIR/500)

printf "\nbig\n"
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
./$EXEC -2147483648 -2147483647 -2147483640 | ./$CHECKER -2147483648 -2147483647 -2147483640
# lagestest
./$EXEC 2147483647 | ./$CHECKER 2147483647
./$EXEC 2147483647 2147483646 2147483640 | ./$CHECKER 2147483647 2147483646 2147483640
