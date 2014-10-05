# created 27 Sep 2008
# by Danny Hoodin
# cs225 mp3

# change SOURCE to a different directory to run this script on your code
SOURCE=../mp3
EXENAME=mp3

for file in `cat RequiredFiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=54

for ((i=1;i<=$TC;i+=1)); do
  echo "Running Test #$i..."
  cat ./test.$i | ./$EXENAME > ./temp.grade
  diff ./temp.grade ./test.$i.std
  rm ./temp.grade
done

make clean

for file in `cat RequiredFiles`
do
  rm $file
done

