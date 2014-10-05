#!/bin/bash
allimgs="outHalf.bmp
outCopy.bmp
outRotated.bmp
outPruned.bmp
outEtc.bmp"

make all -q
if [ $? -ne 0 ]
then
	make all
	if [ $? -ne 0 ]
	then
		exit -1
	fi
fi

./mp5 > outmp5.out
diff outmp5.out soln_mp5.out

for image in $allimgs
do
	diff $image soln_$image
done

