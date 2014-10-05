 #!/bin/bash
 
# EDIT ME IF THIS IS NOT THE PATH TO YOUR gcc-4.1!
CC=g++
 
# Clean up and build our tester
rm -f simpleone simpleone.out h_chan_test h_chan_test.out
$CC -g -o simpleone simpleone.cpp
$CC -g -o h_chan_test h_chan_test.cpp
 
echo "running simpleone..."
./simpleone > simpleone.out
 
echo "run complete! diffing..."
 
diff soln_simpleone.out simpleone.out
 
echo "diff complete!"
 
echo "running h_chan_test..."
./h_chan_test > h_chan_test.out
 
echo "run complete! diffing..."
 
diff soln_h_chan_test.out h_chan_test.out
 
echo "diff complete!"
 
rm -f simpleone h_chan_test
