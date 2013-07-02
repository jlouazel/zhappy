#!/bin/sh

clean
res=$(svn add `find -name "*.c" -or -name "*.h"` | grep A | wc -l)
clear
echo -e "\n\n\n\t\t\t\t\t\t ------- Files added : $res -------\n\n\n"
