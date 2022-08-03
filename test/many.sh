#!/bin/bash

CHECKER=checker_linux
cat /etc/os-release > /dev/null 2>&1 
if [ $? -eq "1" ]
then
	CHECKER=checker_Mac
fi

EXEC=push_swap
RES_DIR=./test/resource

FILE=$1

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
