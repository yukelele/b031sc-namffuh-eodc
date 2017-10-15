CXX=g++

CXXFLAGS = -std=c++11 -Wall

all: frequencies

frequencies: frequencies.o
	${CXX} $^ -o $@

all: huffman

huffman: huffman.o
	${CXX} $^ -o $@

all: encode

encode: encode.o
	${CXX} $^ -o $@

all : decode

decode: decode.o
	${CXX} $^ -o $@

clean: 
	/bin/rm -f frequencies huffman encode decode *.o *~