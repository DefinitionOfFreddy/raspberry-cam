CFLAGS=-g -std=c99 -I. -Wall -Wextra
#CFLAGS=-g   -Wall -Wextra

#all : main.o image.o array.o
#	gcc $(CFLAGS) -o  main main.o image.o array.o -lm -lz

#main.o : main.c
#	gcc -c $(CFLAGS) main.c


main: main.c
	gcc -o $@ $^

testcercle: testcercle.o imp_exp.o type.o
	gcc -o $@ $^

testcercle2: testcercle2.o imp_exp.o type.o cercle.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< $(CFLAGS)
clean:
	rm *.o
