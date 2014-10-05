# created 13 Mar 2010
# by Shivaram Venkataraman, Varun Kumar Singh
# cs225 mp4

# change SOURCE to a different directory to run this script on your code
SOURCE=../mp4
EXENAME=mp4

for file in `cat RequiredFiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
TC=29

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
