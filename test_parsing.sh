#!/bin/bash

for bad_file in ./maps/bad/*; do
	if [ ! -f "$bad_file" ]; then
		continue
	fi
	echo -n "testing $bad_file... "
	./cub3d $bad_file 2>/dev/null >&2
	if [ $? -eq 0 ]; then
		echo "KO"
	else
		echo "OK"
	fi
done
