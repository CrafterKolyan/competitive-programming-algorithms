.PHONY: all

all: cpp-test-all

cpp-test-all: main.cpp
	g++ -std=c++11 -isystem . -isystem .. -pthread $^ libgtest.lib -o $@