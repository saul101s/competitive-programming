#!/bin/bash

filename=$1
extension="${filename##*.}"

if [ -e $filename ]; then
    echo "File $1 already exists"
else
    cp ~/Developer/competitive-programming/templates/competitive-template.$extension ./$filename
fi

if [ -e input.txt ]; then
    echo "File input.txt already exists"
else
    touch input.txt
fi

if [ -e output.txt ]; then
    echo "File output.txt already exists"
else
    touch output.txt
fi

if [ -e error.txt ]; then
    echo "File error.txt already exists"
else
    touch error.txt
fi

geany $filename input.txt output.txt &
