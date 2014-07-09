CFLAGS=-g -I. -Wall -Wextra

main: main.c
	gcc -o $@ $^

%.o: %.c
	gcc -c $< $(CFLAGS)