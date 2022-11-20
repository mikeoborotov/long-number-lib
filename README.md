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
    + [I/O operators](#IO-operators)
    + [Useful getters](#Useful-getters)
    + [Relational operations](#Relational-operations)
    + [Mathematical operations](#Mathematical-operations)
    + [Random numbers](#Random-numbers)
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
This library introduces a new namespace `LNL` (short for LongNumberLib). Inside this namespace there is a `LNL::LongInt` class (arbitrary length integer class) and some functions for mathematical operations.

### Creating an instance
It is possible to create a `LNL::LongInt` instance in different ways: with a `short`, `int`, `long`, `long long` or with unsigned equivalents of these types. It is also possible to create an instance with a `std::string`. If you do not pass a value to the constructor then an instance is initialized with 0 by default.

If you try to initialize with a `std::string` which contains non-digit characters (except front "-") then an instance will be initialized with 0 and an error message will be printed.

Here are some examples:
```c++
LNL::LongInt x;                              // x = 0 (by default)
LNL::LongInt y(-123456789);                  // y = -123456789
LNL::LongInt z("1234567898765432123456789"); // z = 1234567898765432123456789
```

### Assigning a value
Assignment operator `=` is overloaded for `short`, `int`, `long`, `long long` and unsigned equivalents of these types, as well as for `std::string` and `LNL::LongInt` itself.

If you try to assign with a `std::string` which contains non-digit characters (except front "-") then a 0 value will be assigned and an error message will be printed.

Here are some examples:
```c++
LNL::LongInt x, y(16); // x = 0,   y = 16
y = 32;                // x = 0,   y = 32
y = "-64";             // x = 0,   y = -64
x = y;                 // x = -64, y = -64
```

### I/O operators

Input and output operators `>>` and `<<` are overloaded for the `LNL::LongInt` class and can be used to insert/extract `LNL::LongInt` instances as a stream of characters, just like with the standard version of these operators.

Here is an example code:
```c++
LNL::LongInt x;
std::cout << "Enter a number: ";
std::cin >> x;
std::cout << "The number is: " << x << "\n";
```

And if you run this code:
```
Enter a number: -123456789
The number is: -123456789
```

### Useful getters
Below there is a list of some useful getters featured in `LNL::LongInt` class. For convenience and versatility of use, these functions come in two variations: as a class method and as an outside-a-class function.

List of useful getters:
+ `x.toString()` and `LNL::toString(x)` return number value as a `std::string`.
+ `x.abs()` and `LNL::abs(x)` return absolute number value (as a `LNL::LongInt`).
+ `x.size()` and `LNL::size(x)` return number of digits in a number (as a `long long`).
+ `x.length()` and `LNL::length(x)` are synonyms of `x.size()` and `LNL::length(x)`.
+ `x.isEven()` and `LNL::isEven(x)` check if a number is even (as a `bool`).
+ `x.isOdd()` and `LNL::isOdd(x)` check if a number is odd (as a `bool`).
+ `x.isZero()` and `LNL::isZero(x)` check if a number is equal to 0 (as a `bool`).
+ `x.isOne()` and `LNL::isOne(x)` check if a number is equal to 1 (as a `bool`).
+ `x.isPositive()` and `LNL::isPositive(x)` check if a number is positive (as a `bool`).
+ `x.isNegative()` and `LNL::isNegative(x)` check if a number is negative (as a `bool`).
 
Here `x` is an instance of `LNL::LongInt`.

### Relational operations
Relational operators `==`, `!=`, `>`, `>=`, `<`, `<=` are overloaded for the `LNL::LongInt` class. There are also relational functions like:
+ `LNL::min(x,y)` returns the least of two numbers (as a `LNL::LongInt`).
+ `LNL::max(x,y)` returns the greatest of two numbers (as a `LNL::LongInt`).

Here `x` and `y` are instances of `LNL::LongInt`.

### Mathematical operations
Operators `+`, `-`, `*`, `/`, `%` as well as operators `+=`, `-=`, `*=`, `/=`, `%=` are overloaded for the `LNL::LongInt` class and function just like you would expect them to. The same goes for unary operators `+`, `-` and `++`, `--` (both prefix and postfix).

Some other mathematical functions:
+ `LNL::pow(x,y)` calculates `x` to the power of `y` (as a `LNL::LongInt`).
+ `LNL::div(x,y)` performs a division of two numbers an returns a `lidiv_t` type structure (more about it below).
+ `LNL::mod(x,y)` performs a modulo operation `x mod y` (as a `LNL::LongInt`). Consider the the difference between this modulo operation and the division remainder operator `%`!
+ `LNL::gcd(x,y)` returns the greatest common divisor of two numbers (as a `LNL::LongInt`).
+ `LNL::lcm(x,y)` returns the least common multiple of two numbers (as a `LNL::LongInt`).
+ `LNL::factorial(x)` returns factorial of a number (as a `LNL::LongInt`).

Here `x` and `y` are instances of `LNL::LongInt`.

It was mentioned that `LNL::div(x,y)` function returns a `lidiv_t` type structure. This structure consists of a quotient and a remainder of a division, which looks like this:
```c++
struct lidiv_t {
	LongInt quot;
	LongInt rem;
};
```

Using `LNL::div(x,y)` is faster than operators `/` and `%` if you know you need both quotient and remainder.

### Random numbers

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
