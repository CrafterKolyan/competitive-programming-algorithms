.PHONY: all

ifdef OS
# Windows
GTestLibrary = libgtest.lib
else
# Unix
GTestLibrary = libgtest.a
endif

all: cpp-test-all

cpp-test-all: main.cpp
	g++ -std=c++11 -isystem . -isystem .. -pthread $^ ${GTestLibrary} -o $@
