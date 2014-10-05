SOURCE=../mp6
EXENAME=testall

for file in `cat requiredfiles`
do
  cp $SOURCE/$file .
done

make ./$EXENAME

# Test Count
KDT_TC=24
# Valgrind Test Count
VTC=1
KDTM_TC=8

for ((i=1;i<=$KDT_TC;i+=1)); do
  echo "Running Test #$i..."
  cat ./test.$i | ./$EXENAME >& ./temp.grade
  diff ./temp.grade ./test.$i.std
  rm ./temp.grade
done

for ((i=1;i<=$VTC;i+=1)); do
  let testnum=$i+$KDT_TC
  echo "Running Test #$testnum..."
  cat ./valgrind.$i | valgrind --show-reachable=yes --suppressions=./photomosaic.supp --leak-check=full ./$EXENAME > ./temp.grade
  diff ./temp.grade ./valgrind.$i.std
  rm ./temp.grade
done

for ((i=1+$KDT_TC;i<=$KDTM_TC+$KDT_TC;i+=1)); do
  let testnum=$i+$VTC
  echo "Running Test #$testnum..."
  cat ./test.$i | ./$EXENAME >& ./temp.grade
  diff ./temp.grade ./test.$i.std
  rm ./temp.grade
done

make clean

