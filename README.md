# Competitive Programming Algorithms
[![Build Status](https://img.shields.io/travis/com/CrafterKolyan/competitive-programming-algorithms.svg?label=tests)](https://travis-ci.com/CrafterKolyan/competitive-programming-algorithms)
![Last commit](https://img.shields.io/github/last-commit/CrafterKolyan/competitive-programming-algorithms.svg?)
[![License](https://img.shields.io/github/license/CrafterKolyan/competitive-programming-algorithms.svg?color=blue)](LICENSE)

This repository contains algorithms for competitive programming. It was created in order to fix wrong codes on E-maxx.

## Testing
For now we use googletest (gtest) [v1.8.1](https://github.com/google/googletest/releases/tag/release-1.8.1) as an automatic test system.

Also we use [Travis CI](https://travis-ci.com/) to provide automatic testing of all branches (see tests badge on top).

More info: [cpp/tests/README.md](cpp/tests/README.md)

## Coding Style Convention
We use [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
with some exceptions:
1. **Source files have `.cpp` extension rather than `.cc`** <br />
As this code can be used by newbies and `.cpp` extension is the most popular we don't want to
create additional difficulties connected with understanding where the code is placed (and why do we use `.cc` extension).
2. **No need to create header (`.h`) files.** <br />
We want to keep structure as simple as possible.
One source file with implementation and one with tests.
It should be possible to copy an implementation and paste it anywhere.
3. **Possibility of including source (`.cpp`) files**. <br />
This is due to previous exception.<br />
As the wording is complicated we provide an example:<br />
`#include "../binary_power/binary_power_tests.cpp"`
