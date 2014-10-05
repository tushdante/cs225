#!/bin/bash

# created 25 Sep 2008
# by Danny Hoodin
# cs225 mp2

# change SOURCE to a different directory to run this script on your code
SOURCE=../mp2
EXENAME=testscene

for file in `cat RequiredFiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=30
# Valgrind Test Count
VTC=3

for ((i=1;i<=$TC;i+=1)); do
  echo "Running Test #$i..."
  cat ./test.$i | ./$EXENAME > ./temp.grade
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

make clean

for file in `cat RequiredFiles`
do
  rm $file
done

