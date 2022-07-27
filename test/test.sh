#!/bin/bash

EXEC=push_swap
CHECKER=checker_Mac

RES_DIR=./test/resource

FILES=($RES_DIR/one_num_no_action.txt $RES_DIR/two_num_no_action.txt)

i=0
while [ $i -ne ${#FILES[@]} ]
do
	ARGS=$(cat ${FILES[i]})
	./$EXEC $ARGS | ./$CHECKER $ARGS
	i=$((i+1))
done