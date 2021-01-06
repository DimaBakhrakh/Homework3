all: libmyBank.a bank.exe

bank.exe: main.o
	gcc -Wall -o bank.exe main.o libmyBank.a

libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c

main.o: main.c myBank.h
	gcc -Wall -c main.c

.PHONY: all clean

clean:
	rm *.o *.a *.exe