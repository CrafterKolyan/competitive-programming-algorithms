.PHONY: all clean

CC = g++
CXX_FLAGS = -std=c++11 -I . -I .. -pthread

SOURCES = $(wildcard ../*/*.cpp)

ifdef OS
# Windows
GTestLibrary = libgtest.lib
else
# Unix
GTestLibrary = libgtest.a
endif

all: cpp-test-all

cpp-test-all: $(SOURCES)
	$(CC) $(CXX_FLAGS) main.cpp ${GTestLibrary} -o $@

clean:
	rm -f cpp-test-all cpp-test-all.exe
