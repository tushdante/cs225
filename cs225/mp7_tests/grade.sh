#!/bin/bash

# created 16 Nov 2008
# by Danny Hoodin
# cs225 mp7

# change SOURCE to a different directory to run this script on your code

if [ "$1" != "clean" ]; then

SOURCE=../mp7
EXENAME=testall

for file in `cat requiredfiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=19
# Valgrind Test Count
VTC=0

for ((i=1;i<=$TC;i+=1)); do
  echo "Running Test #$i..."
  cat ./test.$i | ./$EXENAME >& ./temp.grade
  diff ./temp.grade ./test.$i.std
  rm ./temp.grade
done

fi

make clean

