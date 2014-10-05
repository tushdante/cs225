#!/bin/bash

# EDIT ME IF THIS IS NOT THE PATH TO YOUR GCC 4.1!
CC=g++

# Clean up and build our tester
rm -f simpletwo simpletwo.out
$CC -g -o simpletwo simpletwo.cpp

echo "running simpletwo..."
./simpletwo > simpletwo.out

echo "run complete! diffing..."

diff soln_simpletwo.out simpletwo.out

echo "diff complete!"

rm -f simpletwo
