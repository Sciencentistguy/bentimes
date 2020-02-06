CC=gcc
CXX=g++

CLFLAGS = -O2 -Wall -std=gnu18 -I.
CXXFLAGS = -O2 -Wall -std=gnu++2a -I.

OBJ = main.o

EXECNAME = bentimes

all: main
	echo build finished

main: $(OBJ)
	$(CXX) -o $(EXECNAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(EXECNAME)
