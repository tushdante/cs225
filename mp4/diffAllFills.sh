#!/bin/bash
allgifs="
gradientColorPickerTest.bmp
gridColorPickerTest.bmp
solidColorPickerTest.bmp
dfsGradientTest.gif
dfsGridTest.gif
dfsSolidTest.gif
bfsGradientTest.gif
bfsGridTest.gif
bfsSolidTest.gif
pacManDFS.bmp
pacManBFS.bmp
antiPacManDFS.gif
antiPacManBFS.gif"

make all
if [ $? -ne 0 ]
then
	exit -1
fi

./testFills all > testFills.out
diff testFills.out soln_testFills.out

for image in $allgifs
do
	diff $image soln_$image
done

