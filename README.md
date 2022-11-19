# LongNumberLib

LNL (short for LongNumberLib) is a C++ library for arithmetics with arbitrary length numbers. It is designed to be simple and easy to use, taking into account possible applications in information security. Current version of LNL only supports arbitrary length integers.

If you find any bugs or if you have improvement suggestions, please feel free to open an issue or a pull request.

WARNING: The library is still under development, so be careful!

## Contents

+ [How to install](#How-to-install)
+ [How to use](#How-to-use)
    + [General info](#General-info)
    + [Creating an instance](#Creating-an-instance)
    + [Assigning a value](#Assigning-a-value)
    + [Useful getters](#Useful-getters)
    + [Relational operations](#Relational-operations)
    + [Mathematical operations](#Mathematical-operations)
    + [More functions](#More-functions)
    + [Information security features](#Information-security-features)
+ [Running tests](#Running-tests)
+ [Benchmarks](#Benchmarks)
+ [Licence](#Licence)

## How to install

The whole library is located in the `LongNumberLib.h` header. You can find it in the `include` directory in this repository. Copy the this file to your project and include it just like any other header:

```c++
#include "<YourPath>/LongNumberLib.h"
```

[:arrow_up: Back to contents](#Contents)

## How to use

### General info
This library introduces a new namespace `LNL` (short for LongNumberLib). Inside this namespace there is a `LongInt` class (arbitrary length integer class) and some functions for mathematical operations.

### Creating an instance
It is possible to create a `LongInt` instance in different ways: with a `short`, `int`, `long`, `long long` or with unsigned equivalents of these types. It is also possible to create an instance with a `std::string`. If you do not pass a value to the constructor then an instance is initialized with 0 by default.

Here are some examples:
```c++
LNL::LongInt x;                              // x = 0 (by default)
LNL::LongInt y(-123456789);                  // y = -123456789
LNL::LongInt z("1234567898765432123456789"); // z = 1234567898765432123456789
```

### Assigning a value
Assignment operator `=` is overloaded for `short`, `int`, `long`, `long long` and unsigned equivalents of these types, as well as for `std::string` and `LNL::LongInt` itself.

Here are some examples:
```c++
LNL::LongInt x, y(16); // x = 0,   y = 16
y = 32;                // x = 0,   y = 32
y = "-64";             // x = 0,   y = -64
x = y;                 // x = -64, y = -64
```

### Useful getters
Below there is a list of some useful getters featured in `LongInt` class. For convenience and versatility of use, these functions come in two variations: as a class method and as a outside-a-class function.

List of useful getters:
+ Use `.toString()` or `LNL::toString(x)` to get number value as a std::string
+ Use `.abs()` or `LNL::abs(x)` to get absolute number value
COMING SOON

### Relational operations
COMING SOON

### Mathematical operations
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

## Licence

COMING SOON

[:arrow_up: Back to contents](#Licence)
