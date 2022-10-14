Nadia Makmak
USC CSCI104 Fall 2022

1&2: llrec-test.cpp main is split into two sections, one for testing LLPivot and one for testing LLFilter. User may uncomment code based on which function they are testing. The functor can be found right above the main(), struct OddComp. There should be no valgrind errors. To run:

$ make
$ ./llrec-test llrec-test1.in

3: stack-test.cpp is a testing file I created for the purpose of testing stack.h. To run:

$ g++ -g -Wall --std=c++11 stack-test.cpp -o stack-test
$ ./stack-test

heap.h is extensively commented throughout. I added heapify() and trickleUp() on my own, using the algorithms part of the lecture slides with a few modifications (made heapify() check if at leaf node for optimization). All tests are passed and should run free of any valgrind error. To run (make sure in /heap_test):

$ make
$ make test
$ make valgrind

My .png outputs are in the repo (my_and.png, my_exclusive.png, my_not.png, my_or.png) and should match output .png's that were in the folder originally. To run (make sure in /logicsim):

$ make
$ ./logicsim <text filename>
$ ./logicsim <text filename> > <outputname>.uml
$ java -jar plantuml.jar <outputname>.uml

