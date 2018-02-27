CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

unittest1.out: unittest1
	./unittest1 &> unittest1.out
	gcov unittest1.c >> unittest1.out
	cat unittest1.c.gcov >> unittest1.out
	gcov -b dominion.c >> unittest1.out
	cat dominion.c.gcov >> unittest1.out
	
unittest2.out: unittest2
	./unittest2 &> unittest2.out
	gcov unittest2.c >> unittest2.out
	cat unittest2.c.gcov >> unittest2.out
	gcov -b dominion.c >> unittest2.out
	cat dominion.c.gcov >> unittest2.out

unittest3.out: unittest3
	./unittest3 &> unittest3.out
	gcov unittest3.c >> unittest3.out
	cat unittest3.c.gcov >> unittest3.out
	gcov -b dominion.c >> unittest3.out
	cat dominion.c.gcov >> unittest3.out

unittest4.out: unittest4
	./unittest4 &> unittest4.out
	gcov unittest4.c >> unittest4.out
	cat unittest4.c.gcov >> unittest4.out
	gcov -b dominion.c >> unittest4.out
	cat dominion.c.gcov >> unittest4.out
	
cardtest1.out: cardtest1
	./cardtest1 &> cardtest1.out
	gcov cardtest1.c >> cardtest1.out
	cat cardtest1.c.gcov >> cardtest1.out
	gcov -b dominion.c >> cardtest1.out
	cat dominion.c.gcov >> cardtest1.out
	
cardtest2.out: cardtest2
	./cardtest2 &> cardtest2.out
	gcov cardtest2.c >> cardtest2.out
	cat cardtest2.c.gcov >> cardtest2.out
	gcov -b dominion.c >> cardtest2.out
	cat dominion.c.gcov >> cardtest2.out
	
cardtest3.out: cardtest3
	./cardtest3 &> cardtest3.out
	gcov cardtest3.c >> cardtest3.out
	cat cardtest3.c.gcov >> cardtest3.out
	gcov -b dominion.c >> cardtest3.out
	cat dominion.c.gcov >> cardtest3.out
	
cardtest4.out: cardtest4
	./cardtest4 &> cardtest4.out
	gcov cardtest4.c >> cardtest4.out
	cat cardtest4.c.gcov >> cardtest4.out
	gcov -b dominion.c >> cardtest4.out
	cat dominion.c.gcov >> cardtest4.out

randomtestcard1.out: randomtestcard1
	./randomtestcard1 &> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2
	./randomtestcard2 &> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer badTestDrawCard badTestDrawCard.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
