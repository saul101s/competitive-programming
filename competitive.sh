#!/bin/bash

if [ "$1" = "close" ]; then
    subl --command "close_all"
    pkill subl
    exit
fi

if [ -e $1 ]; then
    echo "File $1 already exists"
else
    touch $1
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

subl --command "focus_group { \"group\": 0 }" && subl $1
subl --command "focus_group { \"group\": 1 }" && subl output.txt
subl --command "focus_group { \"group\": 2 }" && subl error.txt
subl --command "focus_group { \"group\": 3 }" && subl input.txt
subl --command "focus_group { \"group\": 0 }"