#!/usr/bin/env bash

ext=jpg
for fn in $(ls *.$ext -1)
do
    i=${fn%.*} # strip extension
    mv $fn $(printf "%04d.$ext" $i) # add leading zeros
done
