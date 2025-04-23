#!/bin/bash

WHITE='\033[1;37m'
GREEN='\033[0;32m'
RED='\033[0;31m'

FAIL=0
PASS=0
for bad_file in ./maps/bad/*; do
	if [ ! -f "$bad_file" ]; then
		continue
	fi
	echo -en "${WHITE}testing $bad_file... "
	./cub3d $bad_file 2>/dev/null >&2
	if [ $? -eq 0 ]; then
		echo -e "${RED}FAIL${WHITE}"
		FAIL=$(($FAIL + 1))
	else
		echo -e "${GREEN}PASS${WHITE}"
		PASS=$(($PASS + 1))
	fi
done

echo
echo "FAIL: $FAIL"
echo "PASS: $PASS"
