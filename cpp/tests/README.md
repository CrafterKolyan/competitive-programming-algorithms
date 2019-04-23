# Automatic test system
This is an automatic test system. It is used in order to validate that the written algorithms are correct. It has found a bug in a binary power algorithm, so that is pretty useful.

## Usage
### Windows
Run `cpp-test-all.exe` from the console.

### Unix
Run `cpp-test-all` from the console.

## Compiling

### Windows
If you have `make` installed, you can just use it:
```
make
```
Otherwise you can use the following command:
```
g++ -std=c++11 -I . -I .. -pthread main.cpp libgtest.lib -o cpp-test-all
```

### Unix
If you have `make` installed, you can just use it:
```
make
```
Otherwise you can use the following command:
```
g++ -std=c++11 -I . -I .. -pthread main.cpp libgtest.a -o cpp-test-all
```
