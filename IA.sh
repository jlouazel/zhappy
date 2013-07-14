#!/bin/zsh

if [ $# = 3 ]
then
    for (( i=0; i < 12; i++ ))
    do
	./IA/main.py -n $1 -h $2 -p $3
	sleep 5s
    done
else
    echo "Usage : ./IA.sh [TEAM] [HOST] [PORT]"
fi