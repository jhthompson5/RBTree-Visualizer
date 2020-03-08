README
RBTree Visualizer - JThompson
This visualizer definitely works in Cygwin and will work in any other terminal that supports ANSI codes. If yours doesn't, sorry, the node colors probably won't work but hopefully it still runs and lays out your tree right. Make sure you resize your window to be wide  enough or it will auto-wrap text and look dumb.

This function expects your tree as a parameter. IT WILL CALL YOUR COPY CONSTRUCTOR. If your copy constructor doesn't work yet, you can work around this by changing the tree parameter to a pointer (*tree) and changing the two references to tree to use -> instead of . in the method.
Also, if you used some form of T.nil, change any reference you see to nullptr to compare with that instead.
To use this method, just #include "visualizer.cpp" in your phase2.cpp file. It is important that you have #ifndefine header guards on your RBTree.cpp file or use an intelligent makefile to build the project or you will get errors when visualizer tries to include your tree file. This is as simple as putting #ifndefine RBTREE at the top of your file and #endif at the bottom. Also if you have a header file change the visualizer #include to use that

This method expects you to have a tree made up of Node objects that have at the very least a left, right and Key parameter. If your Node is a struct, it might work but honestly I can't tell you for sure. You will also need to have RBTree:Size() defined and working. If you get an infinite loop, make sure you are decrementing size when deleting a node. Feel free to let me know if you find any bugs, I've still been finding them on occasion, but with how much I've tested it at this point, the fault probably lies in your class. Sorry.
