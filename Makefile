CXX=g++

CXXFLAGS = -std=c++11 -Wall

all: frequencies

frequencies: frequencies.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f frequencies *.o *~ 

all: huffman

huffman: huffman.o
	${CXX} $^ -o $@

clean: 
	/bin/rm -f huffman *.o *~
