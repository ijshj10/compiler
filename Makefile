CC=gcc
CFLAGS=-Wall -g
OBJS=main.o lex.o improved.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c
lex.o: lex.h lex.c
plain.o: lex.h plain.c
improved.o: lex.h improved.c

clean:
	rm -f *.o
	rm -f $(TARGET)