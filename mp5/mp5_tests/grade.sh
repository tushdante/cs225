#!/bin/bash

# created 13 Oct 2008
# by Danny Hoodin
# cs225 mp5

# change SOURCE to a different directory to run this script on your code

if [ "$1" != "clean" ]; then

SOURCE=../../solution
EXENAME=mp5

for file in `cat RequiredFiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=38
# Valgrind Test Count
VTC=4

for ((i=1;i<=$TC;i+=1)); do
  echo "Running Test #$i..."
  cat ./test.$i | ./$EXENAME >& ./temp.grade
  diff ./temp.grade ./test.$i.std
  rm ./temp.grade
done

for ((i=1;i<=$VTC;i+=1)); do
  let testnum=$i+$TC
  echo "Running Test #$testnum..."
  cat ./valgrind.$i | valgrind --leak-check=full ./$EXENAME > ./temp.grade
  diff ./temp.grade ./valgrind.$i.std
  rm ./temp.grade
done
fi

make clean

for file in `cat RequiredFiles`
do
  rm $file
done

