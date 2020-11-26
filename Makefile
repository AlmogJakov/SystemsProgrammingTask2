CC=gcc
AR=ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -g

all: mains
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs -o libmyBank.a $(OBJECTS_LIB)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains