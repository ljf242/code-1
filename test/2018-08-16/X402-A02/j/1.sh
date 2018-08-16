#!/bin/bash
i=1
while(($i<100))
do
	echo Testing Case $i
	./j < j$i.in > j$i.ans
	echo Done!
	i=$(($i+1))
done
