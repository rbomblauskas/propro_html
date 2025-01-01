CC=gcc
CFLAGS=-Wall

all: main

main: main.o enigma_html.o
	$(CC) $(CFLAGS) -o main main.o enigma_html.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

enigma_html.o: enigma_html.c
	$(CC) $(CFLAGS) -c enigma_html.c

clean:
	rm -f *.o main