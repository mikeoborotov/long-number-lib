# LongNumberLib

LNL (short for LongNumberLib) is a C++ library for arithmetics with arbitrary length numbers. It is designed to be simple and easy to use, taking into account possible applications in information security. Current version of LNL only supports arbitrary length integers.

If you find any bugs or if you have improvement suggestions, please feel free to open an issue or a pull request.

WARNING: The library is still under development, so be careful!

## Contents

+ [How to install](#How-to-install)
+ [How to use](#How-to-use)
    + [General info](#General-info)
    + [Creating an instance](#Creating-an-instance)
    + [Arithmetics](#Arithmetics)
    + [Relational operators](#Relational-operators)
    + [More functions](#More-functions)
    + [Information security features](#Information-security-features)
+ [Running tests](#Running-tests)
+ [Benchmarks](#Benchmarks)

## How to install

The whole library is located in the `LongNumberLib.h` header. You can find it in the `include` directory in this repository. Copy the this file to your project and include it just like any other header:

```c++
#include "<YourPath>/LongNumberLib.h"
```

[:arrow_up: Back to contents](#Contents)

## How to use

### General info
COMING SOON

### Creating an instance
COMING SOON

### Arithmetics
COMING SOON

### Relational operators
COMING SOON

### More functions
COMING SOON

### Information security features
COMING SOON

[:arrow_up: Back to contents](#Contents)

## Running tests

In the `include` folder in this repository you can find a second header called `LongNumberLibTest.h`. You can install this header just like the library itself. It is important to note that both headers should be located in the same directory. Inside this file there is a class `LNL::Test` which contains tests for the `LNL::LongInt` class.

To run all tests at once you can use code below:

```c++
LNL::Test::runAllTests();
LNL::Test::printTestReport();
```

Or if you forked the repository you can run:

```
g++ source/testing.cpp -o testing.out
./testing.out
```

Or compile with whatever compiler you prefer.

[:arrow_up: Back to contents](#Contents)

## Benchmarks

COMING SOON

[:arrow_up: Back to contents](#Contents)