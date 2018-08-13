#!/bin/bash
INPUT=$1
MAX_D=$2
if [ ! $INPUT ] ;
then
	echo "You must specify a target to search for";
	exit 1;
fi;
if [ ! -e ./bin/run ] ;
then
	make 1>/dev/null
fi;
echo "Searching for $INPUT:";
curl -s -X GET https://raw.githubusercontent.com/christianp/nulac/master/2of12inf.txt | ./bin/run $INPUT $MAX_D
exit 0;