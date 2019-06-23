.PHONY: all clean

ifndef CXX
CXX = g++
endif
CXX_FLAGS = -std=c++11 -I . -I .. -pthread

SOURCES = $(wildcard ../*/*.cpp)

ifdef OS
# Windows
GTestLibrary = libgtest.lib
DELETE_COMMAND = del /f
else
# Unix
GTestLibrary = libgtest.a
DELETE_COMMAND = rm -f
endif

all: cpp-test-all

cpp-test-all: $(SOURCES)
	$(CXX) $(CXX_FLAGS) main.cpp ${GTestLibrary} -o $@

clean:
	$(DELETE_COMMAND) cpp-test-all cpp-test-all.exe
