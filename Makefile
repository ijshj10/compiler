CC=gcc
CFLAGS=-Wall -g
OBJS=main.o lex.o plain.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c
lex.o: lex.h lex.c
plain.o: lex.h plain.c

clean:
	rm -f *.o
	rm -f $(TARGET)