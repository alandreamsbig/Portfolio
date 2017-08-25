#!/bin/bash
#count.bash
for file in *; do
count=`wc -lw < $file`
echo "${file##*/}" "$count" 
done

