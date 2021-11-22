CC = gcc
FLAGS = -Wall -g
AR = ar
OBJFILES = main.o my_mat.o

all: connections
connections: $(OBJFILES)
	$(CC) $(FLAGS) -o connections $(OBJFILES)
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
clean:
	rm -f connections *.o