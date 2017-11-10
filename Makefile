CFLAGS:=-Wall -Werror

all: main

main: main.o parse_args.o
	gcc -o main main.o parse_args.o

main.o: main.c parse_args.h
	gcc $(CFLAGS) -c main.c

parse_args.o: parse_args.c parse_args.h
	gcc $(CFLAGS) -c parse_args.c

clean:
	rm -f *~ *.exe *.o main

run: all
	./main
