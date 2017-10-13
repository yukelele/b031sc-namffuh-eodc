CXX=g++

CXXFLAGS = -std=c++11 -Wall

all: frequencies

frequencies: frequencies.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f prog1 *.o *~ 
