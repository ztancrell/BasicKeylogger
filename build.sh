#!/bin/bash

SRC="src/main.cpp"
OUT="build/BasicKeylogger"
STD="c++11"
CMD="g++ -std=${STD} -o ${OUT} ${SRC} -pthread"

echo "Building with: $CMD"
echo "C++ standard version: $STD"
$CMD

echo ""
