#!/bin/bash

EXEC=push_swap
CHECKER=checker_Mac

RES_DIR=./test/resource

FILE=$RES_DIR/all_5
cat $FILE

# add test for 5 buy 12

i=0
while [ $i -ne ${#FILES[@]} ]
do
	line=$(head -n $i $FILE)
	echo line
	# ARGS=$(cat ${FILES[i]})
	# ./$EXEC $ARGS | ./$CHECKER $ARGS
	i=$((i+1))
done

printf "\nall 5\n"
