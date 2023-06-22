CC=gcc
CFLAGS=-g -Wall
OBJS=main.o foo.o bar.o
TARGET=main.exe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: foo.h bar.h main.c
foo.o: foo.h foo.c
bar.o: bar.h bar.c

clean:
	rm -f *o
	rm -f $(TARGET)

