#!/bin/bash

EXEC=push_swap
CHECKER=checker_linux

RES_DIR=./test/resource

FILE=$RES_DIR/all_6

i=1
while [ $i -ne $(cat $FILE | wc -l) ]
do
	index=${i}p
	line=$(sed -n $index $FILE)
	stt=$(./$EXEC $line | ./$CHECKER $line)
	num_of_action=$(./$EXEC $line | wc -l)
	printf "%s %d\n" $stt $num_of_action
	i=$((i+1))
done

printf "\nall 5\n"
