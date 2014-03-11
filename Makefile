CC=clang++
CFLAGS=-Wall -Wno-deprecated -std=c++11
LDFLAGS=

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst %.cpp, %, $(wildcard *.cpp))

#Rule how to create arbitary compiled files from cpp.
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
%: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	git clean -xf
