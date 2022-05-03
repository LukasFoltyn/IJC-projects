# *************************************************************#
# Makefile						                               #
# Reseni DU1-IJC, priklad a,b					               #
# Autor: Lukas Foltyn						                   #
# Fakulta: VUT - Fakulta informacnich technologii		       #
# Polsedni zmena: 8.3.2020					                   #
# Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		   #
# *************************************************************#
CC = -cc
CFLAGS = -std=c11 -pedantic -Wall -Wextra 
objects = primes.o eratosthenes.o error.o
objects_decode = eratosthenes.o error.o ppm.o steg-decode.o
objects_inline = primes-i.o eratosthenes-i.o inline.o
objects_encode = eratosthenes.o error.o ppm.o steg-encode.o
STACK_RESIZE = 65000

all: primes primes-i steg-decode steg-encode

primes:$(objects)
	$(CC) $(objects) -lm -o primes

primes.o:primes.c bitset.h
	$(CC) $(CFLAGS) -c primes.c	

eratosthenes.o:eratosthenes.c bitset.h
	$(CC) $(CFLAGS) -c eratosthenes.c

error.o:error.c error.h
	$(CC) $(CFLAGS) -c error.c	

primes-i:$(objects_inline)
	$(CC) $(objects_inline) error.o -lm -o primes-i

primes-i.o:primes.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

inline.o: inline.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c inline.c -o inline.o

steg-decode:$(objects_decode)
	$(CC) $(objects_decode) -lm -o steg-decode

steg-decode.o:steg-decode.c bitset.h ppm.h error.h
	$(CC) $(CFLAGS) -c steg-decode.c

ppm.o:ppm.c error.h ppm.h bitset.h
	$(CC) $(CFLAGS) -c ppm.c

steg-encode:$(objects_encode)
	$(CC) $(objects_encode) -lm -o steg-encode

steg-encode.o:steg-encode.c bitset.h error.h ppm.h
	$(CC) $(CFLAGS) -c steg-encode.c


.PHONY : clean run zip

zip: *.h *.c Makefile
	zip xfolty17 *.h *.c Makefile

clean:
	rm primes primes-i steg-decode ppm.o steg-decode.o steg-encode steg-encode.o $(objects) $(objects_inline)

run: primes primes-i	
	ulimit -s $(STACK_RESIZE); ./primes
	ulimit -s $(STACK_RESIZE); ./primes-i

