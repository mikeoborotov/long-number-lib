## About LNL

**LNL** (short for **long number library**) is a single-file open source C++ library for arithmetics with arbitrary length numbers. It is designed to be simple and easy to use, taking into account possible applications in cryptography and information security. Current version of LNL only supports arbitrary length integers.

## Contents

- [How to install](#how-to-install)
- [How to use](#how-to-use)
  - [General info](#general-info)
  - [Creating an instance](#creating-an-instance)
  - [Assigning a value](#assigning-a-value)
  - [I/O operators](#io-operators)
  - [Useful getters](#useful-getters)
  - [Relational operations](#relational-operations)
  - [Mathematical operations](#mathematical-operations)
  - [Random numbers](#random-numbers)
- [Cryptography features](#cryptography-features)
- [Benchmarks](#benchmarks)
  - [Multiplication](#multiplication)
  - [Division](#division)
  - [Exponentiation](#exponentiation)
  - [General benchmark info](#general-benchmark-info)
- [Testing the library](#testing-the-library)
  - [Run unit tests](#run-unit-tests)
  - [Run benchmarks](#run-benchmarks)
- [Contributing](#contributing)
- [Licence](#licence)

## How to install

The whole library is located in the `LNL.h` header. You can find it in the `include` directory in this repository. Copy the this file to your project and include it just like any other header:

```c++
#include "<YourPath>/LNL.h"
```

[:arrow_up: Back to contents](#contents)

## How to use

### General info
This library introduces a new namespace `LNL` (short for **long number library**). Inside this namespace there is a `LNL::LongInt` class (arbitrary length integer class) and some functions for mathematical operations.

### Creating an instance
It is possible to create a `LNL::LongInt` instance in different ways: with a `short`, `int`, `long`, `long long` or with unsigned equivalents of these types. It is also possible to create an instance with a `std::string`. If you do not pass a value to the constructor then an instance is initialized with 0 by default.

If you try to initialize with a `std::string` which contains non-digit characters (except front `-`) then an instance will be initialized with 0 and an error message will be printed.

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
+ `x.abs()` and `LNL::abs(x)` return absolute number value (returns `LNL::LongInt`).
+ `x.size()` and `LNL::size(x)` return number of digits in a number (returns `long long`).
+ `x.length()` and `LNL::length(x)` are synonyms of `x.size()` and `LNL::length(x)`.
+ `x.isEven()` and `LNL::isEven(x)` check if a number is even (returns `bool`).
+ `x.isOdd()` and `LNL::isOdd(x)` check if a number is odd (returns `bool`).
+ `x.isZero()` and `LNL::isZero(x)` check if a number is equal to 0 (returns `bool`).
+ `x.isOne()` and `LNL::isOne(x)` check if a number is equal to 1 (returns `bool`).
+ `x.isPositive()` and `LNL::isPositive(x)` check if a number is positive (returns `bool`).
+ `x.isNegative()` and `LNL::isNegative(x)` check if a number is negative (returns `bool`).
 
Here `x` is an instance of `LNL::LongInt`.

### Relational operations
Relational operators `==`, `!=`, `>`, `>=`, `<`, `<=` are overloaded for the `LNL::LongInt` class. There are also relational functions like:
+ `LNL::min(x,y)` returns the least of two numbers (returns `LNL::LongInt`).
+ `LNL::max(x,y)` returns the greatest of two numbers (returns `LNL::LongInt`).

Here `x` and `y` are instances of `LNL::LongInt`.

### Mathematical operations
Operators `+`, `-`, `*`, `/`, `%`, `<<`, `>>` as well as operators `+=`, `-=`, `*=`, `/=`, `%=` are overloaded for the `LNL::LongInt` class and function just like you would expect them to. The same goes for unary operators `+`, `-` and `++`, `--` (both prefix and postfix).

Some other mathematical functions:
+ `LNL::pow(x,y)` calculates `x` to the power of `y` (returns `LNL::LongInt`).
+ `LNL::div(x,y)` performs a division of two numbers an returns a `lidiv_t` type structure (more about it below).
+ `LNL::mod(x,y)` performs a modulo operation `x mod y` (returns `LNL::LongInt`). Consider the the difference between this modulo operation and the division remainder operator `%`!
+ `LNL::gcd(x,y)` returns the greatest common divisor of two numbers (returns `LNL::LongInt`).
+ `LNL::lcm(x,y)` returns the least common multiple of two numbers (returns `LNL::LongInt`).
+ `LNL::factorial(x)` returns factorial of a number (returns `LNL::LongInt`).

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

There are multiple ways to generate random numbers in LNL:

+ `LNL::random()` generates a random number of random size (returns `LNL::LongInt`).
+ `LNL::random(x,y)` generates a random number in range from `x` to `y` (returns `LNL::LongInt`).
+ `LNL::random(s)` generates a random number of size `s` (returns `LNL::LongInt`).

Here `x` and `y` are instances of `LNL::LongInt` and `s` is a `long long`.

## Cryptography features

LNL features some functions useful for cryptography and information security, which could be used for further implementation of more complex cryptography algorithms. Below is a list of currently implemented functions:

+ `x.isMillerRabinPrime()` checks if a number is a prime using a probabilistic primality test (returns `bool`).
+ `LNL::randomPrime(s)` generates a random prime number of size `s` (returns `LNL::LongInt`).
+ `LNL::modPowTwo(x,s,y)` performs a modular exponentiation of `x` by 2 to the power of `s` with a modulus `z` (returns `LNL::LongInt`).
+ `LNL::modPow(x,y,z)` performs a modular exponentiation of `x` by `y` with a modulus `z` (returns `LNL::LongInt`).
+ `LNL::shiftEncrypt(x, s)` is a Caesar's cipher encryption which is performed on number `x` with a key `s` (returns `void`, encrypts the number `x`).
+ `LNL::shiftDecrypt(x, s)` is a Caesar's cipher decryption which is performed on number `x` with a key `s` (returns `void`, decrypts the number `x`).

Here `x`, `y`, `z` are instances of `LNL::LongInt` and `s` is a `long long`.

[:arrow_up: Back to contents](#contents)

## Benchmarks

In this section you can find some benchmarks for the library.

### Multiplication

LNL uses karatsuba divide-and-conquer algorithm for multiplication. It allows to reduce the number single-digit multiplications from $n^2$ (traditional multiplication) to at most $n^{log_23} \approx n^{1.585}$ when multiplying two $n$-digit numbers.

Benchmark plot for multiplication of two $n$-digit numbers:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/mult-benchmark.png? "Multiplication benchmark")

Closeup of the benchmark plot:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/mult-benchmark-zoomed.png? "Multiplication benchmark closeup")

Calculation time $time^{log_32}$ on the last plot is linear which indicates the correctness of the karatsuba algorithm. You can also see that this algorithm outperforms traditional multiplication because the $\sqrt{time}$ plot has logarithmic properties.

### Division

LNL uses traditional long division algorithm which has $n^2$ complexity at worst when dividing two $n$-digit numbers. The algorithm for division may be reworked in the future.

Benchmark plot for division of a $n$-digit number by some constant much smaller number:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/div-benchmark.png? "Division benchmark")

Closeup of the benchmark plot:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/div-benchmark-zoomed.png? "Division benchmark closeup")

Calculation time $\sqrt{time}$ is linear on this plot which points to a $n^2$ complexity as expected. However division is faster the closer the numbers are.

Here is a benchmark plot for division of two $n$-digit numbers:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/div-benchmark-fast.png? "Division benchmark for same length numbers")

### Exponentiation

LNL uses exponentiation by squaring which uses $log_2a$ multiplications when calculating $x^a$. However time complexity is also affected by the complexity of the multiplication algorithm itself (see the [multiplication](#multiplication) section above).

Benchmark plot for exponentiation:

![alt text](https://github.com/mikeoborotov/long-number-lib/blob/master/readme-images/pow-benchmark.png? "Exponentiation benchmark")

### General benchmark info

You can also run benchmarks for other functions and operators of LNL with more specific benchmark parameters. For more information see the [run benchmarks](#run-benchmarks) section.

[:arrow_up: Back to contents](#contents)

## Testing the library

### Run unit tests

In the `include` folder in this repository you can find a second header called `LNL-unit-tests.h`. You can install this header just like the library itself. It is important to note that both headers should be located in the same directory. Inside this file there is a class `LNL::Test` which contains unit tests for the `LNL::LongInt` class.

To run all tests at once you can use code below:

```c++
LNL::Test::runAllTests();
LNL::Test::printTestReport();
```

Or if you forked the repository you can run:

```
g++ source/run-unit-tests.cpp -o run-unit-tests.out
./run-unit-tests.out
```

### Run benchmarks

If you are using Linux OS, you can run benchmarks for some functions and operators to measure their execution time. You can find benchmark implementation in `run-benchmarks.py` and `benchmark.cpp` files in the `source` directory. Here is an example code that you can run in your terminal:

```
python3 source/run-benchmarks.py -path source/benchmark.cpp --pow
```

This will run benchmarks for function `LNL::pow()` and plot the results. For a more detailed understanding of how to run this script, use this command:

```
python3 source/run-benchmarks.py -h
```

[:arrow_up: Back to contents](#contents)

## Contributing

If you find any bugs or if you have improvement suggestions, please feel free to open an issue or a pull request. If you open a pull request, please add some comments to your changes and make sure all tests from `LNL-unit-tests.h` header are running correctly.

[:arrow_up: Back to contents](#contents)

## Licence

All code is licensed under the Apache License, Version 2.0 (the "License"). You may modify, distribute and use this product in private or commercial purposes as long as you preserve the copyright and license notices. See the [LICENSE](LICENSE) file for more detail.

See the [NOTICE](NOTICE) file for copyright information.

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an **"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND**, either express or implied. See the License for the specific language governing permissions and limitations under the License.

[:arrow_up: Back to contents](#contents)
