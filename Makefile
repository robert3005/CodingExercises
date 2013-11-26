CC=clang++
CFLAGS=-Wall -Wno-deprecated -std=c++11
LDFLAGS=

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

#Rule how to create arbitary .out files.
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
%.out: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f core *.out
