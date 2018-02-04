CFLAGS = -Wall -fpic -coverage -lm

testme: 
	gcc -o testme testme.c $(CFLAGS)
	./testme

all: testme

clean: 
	rm -f *.o testme.exe testme
