For the life of me, I could not get my makefile to work in time, but I know that my source files/tests work perfectly fine.
The current "Makefile" gets you the individual code coverage of each function, while the "Makefile1" gets you the overall code coverage and lines hit of dominion.c like it did in previous assignments.
I know I have to be super close as you can see from my makefile, and if I had more time I could probably figure it out, but unfortunately this will have to do for now...
I hate to lose points over something as silly as this... :'(

1) Enter the command "make clean"

2) Enter the command "make unittest[x]" where x is the number of the unittest that you want to run.
3) Enter the command "unittest[x]"
4) Enter the command "gcov unittest[x].c"
5) repeat 2-3 until all unittests (unittest1, unittest2, unittest3, and unittest4) are compiled, ran, and analyzed

6) Enter the command "make cardtest[x]" where x is the number of the cardtest that you want to run.
7) Enter the command "cardtest[x]"
8) Enter the command "gcov cardtest[x].c"
9) repeat 2-3 until all cardtests (cardtest1, cardtest2, cardtest3, and cardtest4) are compiled, ran, and analyzed

10) Enter the command "make randomtestcard[x]" where x is the number of the randomtestcard that you want to run.
11) Enter the command "randomcardtest[x]"
12) Enter the command "gcov randomtestcard[x].c"
13) repeat 2-3 until all randomtestcards (randomtestcard1, randomtestcard2, randomtestcard3, and randomtestcard4) are compiled, ran, and analyzed

14) Enter the command "make randomtestadventurer"
15) Enter the command "randomcardtestadventurer"
16) Enter the command "gcov randomtestcardadventurer.c"

After all of these commands, you should be able to see the gcov code coverage percentage that is outputted to the console, as well as actual lines hit in the respective ".gcov" files.
I'm hoping for a little mercy on this grade, as I worked extremely hard on it, and we were never really taught makefiles at all throughout the entire program, but as you can see my testing should be mostly on point, which should be the main focus of this assignment.
