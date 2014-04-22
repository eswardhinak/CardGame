#!/bin/bash

echo Enter the filename
read fn
for WORD in $(cat $fn)
do
	echo "$WORD"
done | sort -u | wc -l

	for WORD in $(cat $fn)
	do
		echo "$WORD "
	done | sort -u

