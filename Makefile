CC = gcc
AR = ar
FLAGS = -Wall -g
OBJECTS = main.o my_mat.o

all: connections
connections: $(OBJECTS) libmy_mat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS) libmy_mat.a
libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
.PHONY: all clean
clean:
	rm -f connections *.o *.a