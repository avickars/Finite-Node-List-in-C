all: test

test: test.c list.c
	gcc -o test test.c list.c

clean:
	rm test