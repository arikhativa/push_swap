#!/bin/bash

EXEC=push_swap
CHECKER=checker_Mac

RES_DIR=./test/resource

FILES=($RES_DIR/one_num_no_action $RES_DIR/two_num_no_action $RES_DIR/10 $RES_DIR/7 $RES_DIR/many)

i=0
while [ $i -ne ${#FILES[@]} ]
do
	ARGS=$(cat ${FILES[i]})
	./$EXEC $ARGS | ./$CHECKER $ARGS
	i=$((i+1))
done