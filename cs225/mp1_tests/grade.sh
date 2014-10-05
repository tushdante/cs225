#!/bin/bash

# created 29 Jan 2009
# by Danny Hoodin
# cs225 mp1

# change SOURCE to a different directory to run this script on your code

SOURCE=../mp1
EXENAME=mp1

for file in `cat RequiredFiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=17

for ((i=1;i<=$TC;i+=1)); do
  echo "Running Test #$i..."
  read j < ./test.$i
  cp in_$j.bmp in.bmp
  ./$EXENAME >& ./temp.grade
  if [ -e "out.bmp" ]; then
    diff out.bmp out_$j.bmp
    diff ./temp.grade ./test.$i.std
    rm out.bmp
  else
    echo "File out.bmp not found."
  fi
  rm -f ./in.bmp ./temp.grade
done

make clean

for file in `cat RequiredFiles`
do
  rm $file
done

