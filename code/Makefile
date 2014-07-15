#CFLAGS=-g -std=c99 -I. -Wall -Wextra
CFLAGS=-g -std=c99  -Wall -Wextra

all : main.o image.o array.o
	gcc $(CFLAGS) -o  main main.o image.o array.o -lm -lz

main.o : main.c
	gcc -c $(CFLAGS) main.c


#main: main.c
#	gcc -o $@ $^

#%.o: %.c
#	gcc -c $< $(CFLAGS)
