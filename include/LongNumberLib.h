// Copyright 2022 Mikhail Oborotov, Ivan Borisenkov, Elveg Khunshaev
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LONGNUMBERLIB_H
#define LONGNUMBERLIB_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>

// Opening namespace "LNL" (short for "LongNumberLib")
namespace LNL {

/**
 * Structure for quotient and remainder for LongInt div() function.
 * 
 * Stores quotient and remainder after division of two numbers.
 * 
 * @see div
 */
struct lidiv_t;

/**
 * Structure for _isPowerOfTen() function.
 * 
 * Stores whether the number is a power of ten
 * and if it is then the power itself.
 * 
 * @see _isPowerOfTen
 */
struct isPowerOfTen_t;

/**
 * Implementation of arithmetic for big numbers.
 *
 * Stores a large number and allows you to construct big number, 
 * perform any arithmetic operations with it and output it to console.
 *
 */
class LongInt {
private:
	std::vector<int> _digits; // Number as a vector of digits
	bool _positive; // Is number positive?
	void _checkLeadingZeroes(); // Remove leading zeroes
	void _checkDigitOverflow(); // Correct digits if they are beyond 9 or below 0
	void _checkNegativeZero(); // Correct -0 to 0
	static int _compare(const LongInt& firstNum, const LongInt& secondNum); // Compare numbers
	static LongInt _sumAux(const LongInt& biggerNum, const LongInt& smallerNum); // Auxiliary function
	static LongInt _diffAux(const LongInt& biggerNum, const LongInt& smallerNum); // Auxiliary function
	static LongInt _multAux(const LongInt& firstNum, const LongInt& secondNum); // Auxiliary function
	static LongInt _karatsubaAlg(const LongInt& firstNum, const LongInt& secondNum); // Karatsuba algorithm
	static isPowerOfTen_t _isPowerOfTen(const LongInt& number); // Is number a power of 10?
public:
	LongInt(); // Default constructor
	LongInt(signed short input); // Constructor for short
	LongInt(unsigned short input); // Constructor for unsigned short
	LongInt(signed int input); // Constructor for int
	LongInt(unsigned int input); // Constructor for unsigned int
	LongInt(signed long input); // Constructor for long
	LongInt(unsigned long input); // Constructor for unsigned long
	LongInt(signed long long input); // Constructor for long long
	LongInt(unsigned long long input); // Constructor for unsigned long long
	LongInt(const std::string& input); // Constructor for string
	std::string toString() const; // Get number value as a string
	LongInt abs() const; // Get absolute number value
	long long size() const; // Get number size
	long long length() const; // Get number size
	bool isEven() const; // Is number even?
	bool isOdd() const; // Is number odd?
	bool isZero() const; // Is number equal to 0?
	bool isOne() const; // Is number equal to 1?
	bool isPositive() const; // Is number positive?
	bool isNegative() const; // Is number negative?
	friend std::string toString(const LongInt& number); // Get number value as a string
	friend LongInt abs(const LongInt& number); // Get absolute number value
	friend long long size(const LongInt& number); // Get number size
	friend long long length(const LongInt& number); // Get number size
	friend bool isEven(const LongInt& number); // Is number even?
	friend bool isOdd(const LongInt& number); // Is number odd?
	friend bool isZero(const LongInt& number); // Is number equal to 0?
	friend bool isOne(const LongInt& number); // Is number equal to 1?
	friend bool isPositive(const LongInt& number); // Is number positive?
	friend bool isNegative(const LongInt& number); // Is number negative?
	friend std::istream& operator >>(std::istream& in, LongInt& number); // Input stream operator
	friend std::ostream& operator <<(std::ostream& out, const LongInt& number); // Output stream operator
	LongInt& operator =(signed short input); // Set number value with short
	LongInt& operator =(unsigned short input); // Set number value with unsigned short
	LongInt& operator =(signed int input); // Set number value with int
	LongInt& operator =(unsigned int input); // Set number value with unsigned int
	LongInt& operator =(signed long input); // Set number value with long
	LongInt& operator =(unsigned long input); // Set number value with unsigned long
	LongInt& operator =(signed long long input); // Set number value with long long
	LongInt& operator =(unsigned long long input); // Set number value with unsigned long long
	LongInt& operator =(const std::string& input); // Set number value with string
	LongInt& operator =(const LongInt& input); // Set number value with LongInt
	bool operator ==(const LongInt& secondNum) const; // Is this number equal to 2nd?
	bool operator !=(const LongInt& secondNum) const; // Is this number not equal to 2nd?
	bool operator >(const LongInt& secondNum) const; // Is this number greater than 2nd?
	bool operator >=(const LongInt& secondNum) const; // Is this number greater or equal to 2nd?
	bool operator <(const LongInt& secondNum) const; // Is this number less than 2nd?
	bool operator <=(const LongInt& secondNum) const; // Is this number less or equal to 2nd?
	friend LongInt max(const LongInt& firstNum, const LongInt& secondNum); // Return max number
	friend LongInt min(const LongInt& firstNum, const LongInt& secondNum); // Return min number
	LongInt operator +(const LongInt& secondNum) const; // Sum of 2 numbers
	LongInt operator -(const LongInt& secondNum) const; // Difference of 2 numbers
	LongInt operator *(const LongInt& secondNum) const; // Product of 2 numbers
	LongInt operator /(const LongInt& secondNum) const; // Quotient of 2 numbers division
	LongInt operator %(const LongInt& secondNum) const; // Remainder of 2 numbers division
	LongInt& operator +=(const LongInt& secondNum); // Add another number
	LongInt& operator -=(const LongInt& secondNum); // Subtract another number
	LongInt& operator *=(const LongInt& secondNum); // Multiply by another number
	LongInt& operator /=(const LongInt& secondNum); // Divide by another number
	LongInt& operator %=(const LongInt& secondNum); // Remainder of division by another number
	LongInt operator +(); // Return this number (unary plus)
	LongInt& operator ++(); // Add 1 to the number (prefix)
	LongInt operator ++(int); // Add 1 to the number (postfix)
	LongInt operator -(); // Return opposite sign number (unary minus)
	LongInt& operator --(); // Subtract 1 from the number (prefix)
	LongInt operator --(int); // Subtract 1 to the number (postfix)
	LongInt operator >> (LongInt number); // Logical right-shift operator 
	LongInt operator << (LongInt number); // Logical left-shift operator 
	friend LongInt pow(const LongInt& firstNum, const LongInt& secondNum); // firstNum to the power of secondNum
	friend lidiv_t div(const LongInt& firstNum, const LongInt& secondNum); // Division
	friend LongInt mod(const LongInt& firstNum, const LongInt& secondNum); // Modulo
	friend LongInt gcd(const LongInt& firstNum, const LongInt& secondNum); // Greatest common divisor
	friend LongInt lcm(const LongInt& firstNum, const LongInt& secondNum); // Least common multiple
	friend LongInt factorial(const LongInt& number); // Factorial of a number
	friend LongInt Random(); // Generates random LongInt number
};


// Structure for quotient and remainder for LongInt div() function
struct lidiv_t {
	LongInt quot;
	LongInt rem;
};

// Structure for _isPowerOfTen() function
struct isPowerOfTen_t {
	bool isPowerOfTen;
	long long power;
};

// Chesks if LongInt number have leading zeroes and remove them
void LongInt::_checkLeadingZeroes() {
	for (long long i = size() - 1; i > 0; i--) {
		if (_digits[i] == 0) {
			_digits.pop_back();
		} else {
			break;
		}
	}
}

// Correct LongInt number's digits if they are beyond 9 or below 0
void LongInt::_checkDigitOverflow() {
	for (long long i = 0; i < size() - 1; i++) {
		while (_digits[i] > 9) {
			_digits[i] -= 10;
			_digits[i + 1] += 1;
		}
		while (_digits[i] < 0) {
			_digits[i] += 10;
			_digits[i + 1] -= 1;
		}
	}
	if (_digits[size() - 1] > 9) {
		_digits[size() - 1] -= 10;
		_digits.push_back(1);
	}
	while (_digits[size() - 2] > 9) {
		_digits[size() - 2] -= 10;
		_digits[size() - 1] += 1;
	}
}

// Correct LongInt number if it is equal to -0 to 0
void LongInt::_checkNegativeZero() {
	if (isZero()) {
		_positive = true;
	}
}

/**
 * Compare two LongInt numbers (1st relative to 2nd).
 *
 * @param firstNum First number to be compared.
 * @param secondNum Second number to be compared.
 * @return 1 if 1st number is grater than 2nd.
 * 		   2 if numbers are equal.
 * 		  -1 if 1st number is less than 2nd.
 */
int LongInt::_compare(const LongInt& firstNum, const LongInt& secondNum) {
	// Signs: + -
	if (firstNum.isPositive() and secondNum.isNegative()) {
		return 1;
	}
	// Signs: - +
	if (firstNum.isNegative() and secondNum.isPositive()) {
		return -1;
	}
	// Signs: + +
	if (firstNum.isPositive() and secondNum.isPositive()) {
		if (firstNum.size() > secondNum.size()) {
			return 1;
		} else if (firstNum.size() < secondNum.size()) {
			return -1;
		} else {
			for (long long i = firstNum.size() - 1; i >= 0; i--) {
				if (firstNum._digits[i] > secondNum._digits[i]) {
					return 1;
				} else if (firstNum._digits[i] < secondNum._digits[i]) {
					return -1;
				}
			}
		}
	}
	// Signs: - -
	if (firstNum.isNegative() and secondNum.isNegative()) {
		if (firstNum.size() > secondNum.size()) {
			return -1;
		} else if (firstNum.size() < secondNum.size()) {
			return 1;
		} else {
			for (long long i = firstNum.size() - 1; i >= 0; i--) {
				if (firstNum._digits[i] > secondNum._digits[i]) {
					return -1;
				} else if (firstNum._digits[i] < secondNum._digits[i]) {
					return 1;
				}
			}
		}
	}
	return 0; // If numbers are equal
}

/**
 * Auxiliary function for sum().
 *
 * Sums 2 positive numbers (biggerNum >= smallerNum).
 * 
 * @param biggerNum First number for summation.
 * @param smallerNum Second number for summation.
 * @see sum
 */
LongInt LongInt::_sumAux(const LongInt& biggerNum, const LongInt& smallerNum) {
	LongInt result = biggerNum;
	for (long long i = 0; i < smallerNum.size(); i++) {
		result._digits[i] += smallerNum._digits[i];
	}
	result._checkDigitOverflow();
	return result;
}

/**
 * Auxiliary function for sum().
 *
 * Finds the difference of 2 positive numbers (biggerNum >= smallerNum).
 * 
 * @param biggerNum First number for subtraction.
 * @param smallerNum Second number for subtraction.
 * @see sum
 */
LongInt LongInt::_diffAux(const LongInt& biggerNum, const LongInt& smallerNum) {
	LongInt result = biggerNum;
	for (long long i = 0; i < smallerNum.size(); i++) {
		result._digits[i] -= smallerNum._digits[i];
	}
	result._checkDigitOverflow();
	result._checkLeadingZeroes();
	return result;
}

/**
 * Auxiliary function (default multiplication).
 *
 * Multiply two LontInt numbers.
 * 
 * @param firstNum First number for multiplication.
 * @param secondNum Second number for multiplication.
 * @return Member of LongInt class as a result of multiplication.
 */
LongInt LongInt::_multAux(const LongInt& firstNum, const LongInt& secondNum) {
	LongInt result;
	result._digits.resize(firstNum.size() + secondNum.size());
	for (long long i = 0; i < secondNum.size(); i++) {
		for (long long j = 0; j < firstNum.size(); j++) {
			result._digits[i + j] += secondNum._digits[i] * firstNum._digits[j];
		}
	}
	result._checkDigitOverflow();
	result._checkLeadingZeroes();
	return result;
}

/**
 * Implementation of Karatsuba algorithm for fast multiplication. 
 *
 * Implements Karatsuba algorithm for fast multiplication. 
 * Both params are absolute numbers.
 * 
 * @param firstNum First number for multiplication.
 * @param secondNum Second number for multiplication.
 * @return Member of LongInt class as a result of multiplication.
 */
LongInt LongInt::_karatsubaAlg(const LongInt& firstNum, const LongInt& secondNum) {
	// If it is faster to multiply as usual
	if ((firstNum.size() < 100) or (secondNum.size() < 100)) {
		return _multAux(firstNum, secondNum);
	}
	// Algorithm
	LongInt result;
	long long base = std::max(firstNum.size(), secondNum.size());
	long long halfBase = base / 2;
	LongInt A = firstNum / pow(LongInt(10), halfBase);
	LongInt B = firstNum % pow(LongInt(10), halfBase);
	LongInt C = secondNum / pow(LongInt(10), halfBase);
	LongInt D = secondNum % pow(LongInt(10), halfBase);
	LongInt AC = _karatsubaAlg(A, C);
	LongInt BD = _karatsubaAlg(B, D);
	LongInt ADplusBC = _karatsubaAlg(A + B, C + D) - AC - BD;
	result = AC * pow(LongInt(10), 2 * halfBase) + (ADplusBC * pow(LongInt(10), halfBase)) + BD;
	return result;
}

/**
 * Checks if number is power of 10.
 * 
 * @see isPowerOfTen_t
 * 
 * @param number Numbet to be checked.
 * @return Member of isPowerOfTen_t structure.
 */
isPowerOfTen_t LongInt::_isPowerOfTen(const LongInt& number) {
	bool isPowerOfTen = true;
	long long power = 0;
	for (long long i = 0; i < number.size() - 1; i++) {
		if (number._digits[i] != 0) {
			isPowerOfTen = false;
			break;
		} else {
			power++;
		}
	}
	if (number._digits[number.size() - 1] != 1) {
		isPowerOfTen = false;
	}
	return {isPowerOfTen, power};
}

// Default constructor
LongInt::LongInt() {
	_digits.push_back(0); // Number is set to 0 by default
	_positive = true;
}

// Constructor for short
LongInt::LongInt(signed short input) {
	*this = input;
}

// Constructor for unsigned short
LongInt::LongInt(unsigned short input) {
	*this = input;
}

// Constructor for int
LongInt::LongInt(signed int input) {
	*this = input;
}

// Constructor for unsigned int
LongInt::LongInt(unsigned int input) {
	*this = input;
}

// Constructor for long
LongInt::LongInt(signed long input) {
	*this = input;
}

// Constructor for unsigned long
LongInt::LongInt(unsigned long input) {
	*this = input;
}

// Constructor for long long
LongInt::LongInt(signed long long input) {
	*this = input;
}

// Constructor for unsigned long long
LongInt::LongInt(unsigned long long input) {
	*this = input;
}

// Constructor for string
LongInt::LongInt(const std::string& input) {
	*this = input;
}

// Get number as a string
std::string LongInt::toString() const {
	std::string output;
	for (const auto &digit: _digits) {
		output.push_back(digit + '0');
	}
	if (isNegative()) {
		output.push_back('-');
	}
	std::reverse(output.begin(), output.end());
	return output;
}

// Get absolute number value
LongInt LongInt::abs() const {
	LongInt result;
	result = *this;
	result._positive = true;
	return result;
}

// Get number size
long long LongInt::size() const {
	return _digits.size();
}

// Get number size, synonym to size()
long long LongInt::length() const {
	return _digits.size();
}

// Is number even?
bool LongInt::isEven() const {
	return (_digits[0] % 2 == 0);
}

// Is number odd?
bool LongInt::isOdd() const {
	return !isEven();
}

// Is number equal to 0?
bool LongInt::isZero() const {
	if ((size() == 1) and (_digits[0] == 0)) {
		return true;
	}
	return false;
}

// Is number equal to 1?
bool LongInt::isOne() const {
	if ((size() == 1) and (_digits[0] == 1) and _positive) {
		return true;
	}
	return false;
}

// Is number positive?
bool LongInt::isPositive() const {
	return _positive;
}

// Is number negative?
bool LongInt::isNegative() const {
	return !_positive;
}

// Get number value as a string
std::string toString(const LongInt& number) {
	return number.toString();
}

// Get absolute number value
LongInt abs(const LongInt& number) {
	return number.abs();
}

// Get number size
long long size(const LongInt& number) {
	return number.size();
}

// Get number size, synonym to size()
long long length(const LongInt& number) {
	return number.length();
}

// Is number even?
bool isEven(const LongInt& number) {
	return number.isEven();
}

// Is number odd?
bool isOdd(const LongInt& number) {
	return number.isOdd();
}

// Is number equal to 0?
bool isZero(const LongInt& number){
	return number.isZero();
}

// Is number equal to 1?
bool isOne(const LongInt& number) {
	return number.isOne();
}

// Is number positive?
bool isPositive(const LongInt& number) {
	return number.isPositive();
}

// Is number negative?
bool isNegative(const LongInt& number) {
	return number.isNegative();
}

// Input stream operator
std::istream& operator >>(std::istream& in, LongInt& number) {
	std::string input;
	in >> input;
	number = input;
	return in;
}

// Output stream operator
std::ostream& operator <<(std::ostream& out, const LongInt& number) {
	out << number.toString();
	return out;
}

// Set number value with short
LongInt& LongInt::operator =(signed short input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned short
LongInt& LongInt::operator =(unsigned short input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with int
LongInt& LongInt::operator =(signed int input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned int
LongInt& LongInt::operator =(unsigned int input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with long
LongInt& LongInt::operator =(signed long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned long
LongInt& LongInt::operator =(unsigned long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with long long
LongInt& LongInt::operator =(signed long long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned long long
LongInt& LongInt::operator =(unsigned long long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with string
LongInt& LongInt::operator =(const std::string& input) {
	_digits.erase(_digits.begin(), _digits.end());
	if (input.substr(0, 1) == "-") {
		_positive = false;
	} else {
		_positive = true;
	}
	for (long long i = 0; i < input.size(); i++) {
		if ((i == 0) and !_positive) {
			continue;
		}
		// In case of a non-digit character
		if ((input[i] < 48) or (input[i]  > 57)) {
			*this = "0";
			std::cout << "ERROR: A non-digit character \"" << input[i] ;
			std::cout << "\" is encountered when assigning a value of a LongInt with a string.";
			std::cout << " Value is set to 0 by default.\n";
			return *this;
		}
		_digits.push_back(input[i] - '0');
	}
	std::reverse(_digits.begin(), _digits.end());
	_checkLeadingZeroes();
	_checkNegativeZero();
	return *this;
}

// Set number value with LongInt
LongInt& LongInt::operator =(const LongInt& input) {
	_digits.erase(_digits.begin(), _digits.end());
	_digits = input._digits;
	_positive = input._positive;
	return *this;
}

// Is this number equal to 2nd?
bool LongInt::operator ==(const LongInt& secondNum) const {
	if ((this->isPositive() != secondNum.isPositive()) or (this->size() != secondNum.size())) {
		return false;
	}
	for (long long i = 0; i < this->size(); i++) {
		if (this->_digits[i] != secondNum._digits[i]) {
			return false;
		}
	}
	return true;
}

// Is this number not equal to 2nd?
bool LongInt::operator !=(const LongInt& secondNum) const {
	return !(*this == secondNum);
}

// Is this number greater than 2nd?
bool LongInt::operator >(const LongInt& secondNum) const {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return true; // Greater
		case 0: return false; // Equal
		case -1: return false; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is this number greater or equal to 2nd?
bool LongInt::operator >=(const LongInt& secondNum) const {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return true; // Greater
		case 0: return true; // Equal
		case -1: return false; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Is this number less than 2nd?
bool LongInt::operator <(const LongInt& secondNum) const {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return false; // Greater
		case 0: return false; // Equal
		case -1: return true; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is this number less or equal to 2nd?
bool LongInt::operator <=(const LongInt& secondNum) const {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return false; // Greater
		case 0: return true; // Equal
		case -1: return true; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Return max number
LongInt max(const LongInt& firstNum, const LongInt& secondNum) {
	if (firstNum >= secondNum) {
		return firstNum;
	}
	return secondNum;
}

// Return min number
LongInt min(const LongInt& firstNum, const LongInt& secondNum) {
	if (firstNum <= secondNum) {
		return firstNum;
	}
	return secondNum;
}

// Sum of 2 numbers
LongInt LongInt::operator +(const LongInt& secondNum) const {
	LongInt result;
	if (this->isPositive() == secondNum.isPositive()) {
		// If (+,+) or (-,-)
		if (*this >= secondNum) {
			result = _sumAux(*this, secondNum);
		} else {
			result = _sumAux(secondNum, *this);
		}
	} else if (this->isPositive() and secondNum.isNegative()) {
		// If (+,-)
		if (*this >= secondNum.abs()) {
			result = _diffAux(*this, secondNum.abs());
		} else {
			result = _diffAux(secondNum.abs(), *this);
			result._positive = false;
		}
	} else {
		// If (-,+)
		if (this->abs() > secondNum) {
			result = _diffAux(this->abs(), secondNum);
			result._positive = false;
		} else {
			result = _diffAux(secondNum, this->abs());
		}
	}
	result._checkNegativeZero();
	return result;
}

// Difference of 2 numbers
LongInt LongInt::operator -(const LongInt& secondNum) const {
	LongInt temp = secondNum;
	temp._positive = !temp.isPositive();
	return *this + temp;
}

// Product of 2 numbers
LongInt LongInt::operator *(const LongInt& secondNum) const {
	// Checking multiplication by zero
	if (this->isZero() or secondNum.isZero()) {
		return LongInt(0);
	}
	// Checking multiplication by 10 in some power
	isPowerOfTen_t thisInfo = _isPowerOfTen(*this);
	isPowerOfTen_t secondInfo = _isPowerOfTen(secondNum);
	// Algorithm
	LongInt result;
	if (thisInfo.isPowerOfTen) {
		// Multiplication if firstNum is a 10 in some power
		result._digits.resize(thisInfo.power);
		result._digits.insert(result._digits.end(), secondNum._digits.begin(), secondNum._digits.end());
		result._positive = (this->isPositive() == secondNum.isPositive());
		return result;
	} else if (secondInfo.isPowerOfTen) {
		// Multiplication if secondNum is a 10 in some power
		result._digits.resize(secondInfo.power);
		result._digits.insert(result._digits.end(), this->_digits.begin(), this->_digits.end());
		result._positive = (this->isPositive() == secondNum.isPositive());
		return result;
	} else {
		// General multiplication
		result = _karatsubaAlg(this->abs(), secondNum.abs());
		result._positive = (this->isPositive() == secondNum.isPositive());
		return result;
	}
	return result;
}

// Quotient of 2 numbers
LongInt LongInt::operator /(const LongInt& secondNum) const {
	lidiv_t temp = div(*this, secondNum);
	return temp.quot;
}

// Remainder of 2 numbers division
LongInt LongInt::operator %(const LongInt& secondNum) const {
	lidiv_t temp = div(*this, secondNum);
	return temp.rem;
}

// Add another number
LongInt& LongInt::operator +=(const LongInt& secondNum) {
	return *this = *this + secondNum;
}

// Subtract another number
LongInt& LongInt::operator -=(const LongInt& secondNum) {
	return *this = *this - secondNum;
}

// Multiply by another number
LongInt& LongInt::operator *=(const LongInt& secondNum) {
	return *this = *this * secondNum;
}

// Divide by another number
LongInt& LongInt::operator /=(const LongInt& secondNum) {
	return *this = *this / secondNum;
}

// Remainder of division by another number
LongInt& LongInt::operator %=(const LongInt& secondNum) {
	return *this = *this % secondNum;
}

// Return this number (unary plus)
LongInt LongInt::operator +() {
	return *this;
}

// Add 1 to the number (prefix)
LongInt& LongInt::operator ++() {
	return *this = *this + LongInt("1");
}

// Add 1 to the number (postfix)
LongInt LongInt::operator ++(int) {
	return *this = *this + LongInt("1");
}

// Return opposite sign number (unary minus)
LongInt LongInt::operator -() {
	LongInt result;
	result = *this;
	result._positive = !isPositive();
	result._checkNegativeZero();
	return result;
}

// Subtract 1 from the number (prefix)
LongInt& LongInt::operator --() {
	return *this = *this - LongInt("1");
}

// Subtract 1 to the number (postfix)
LongInt LongInt::operator --(int) {
	return *this = *this - LongInt("1");
}

// Logical right-shift operator 
LongInt LongInt::operator >>(LongInt number) {
	return *this = *this / pow(2, number);
}

// Logical left-shift operator 
LongInt LongInt::operator <<(LongInt number) {
	return *this = *this * pow(2, number);
}

/**
 * Calculate power of two LongInt numbers.
 *
 * @param firstNum Number to be raised.
 * @param secondNum The power to which we raise.
 * @return 'firstNum' to the power of 'secondNum'.
 */
LongInt pow(const LongInt& firstNum, const LongInt& secondNum) {
	// If to the power of negative number
	if (secondNum.isNegative()) {
		std::cout << "ERROR: Unable to raise LongInt to the power of negative number!\n";
		return LongInt(0);
	}
	LongInt result;
	// If in to the power of 0
	if (secondNum.isZero()) {
		return LongInt(1);
	}
	// If in to the power of 1
	if (secondNum.isOne()) {
		return firstNum;
	}
	// If 0 in some power
	if (firstNum.isZero()) {
		return LongInt(0);
	}
	// If 1 or -1 in some power
	if (isOne(abs(firstNum))) {
		result = firstNum;
		if (secondNum.isEven()) {
			result._positive = true;
		}
		return result;
	}
	// Checking if firstNum is a 10 to some power
	isPowerOfTen_t firstInfo = LongInt::_isPowerOfTen(firstNum);
	// Algorithm
	LongInt power = secondNum;
	if (firstInfo.isPowerOfTen) {
		// If firstNum is a 10 in some power
		result._digits.resize(firstInfo.power * std::stoi(toString(secondNum)));
		result._digits.push_back(1);
		result._positive = firstNum.isPositive();
		if (firstNum.isNegative() and power.isEven()) {
			result._positive = true;
		}
	} else {
		// General case pow()
		result = pow(firstNum * firstNum, power / 2);
		if (power.isOdd()) {
			result *= firstNum;
		}
	}
	return result;
}

/**
 * Calculate result of division of two LongInt numbers.
 *
 * @see lidiv_t
 * 
 * @param firstNum Number to be devided.
 * @param secondNum Number by which we divide.
 * @return Member of lidiv_t structure as a result of division.
 */
lidiv_t div(const LongInt& firstNum, const LongInt& secondNum) {
	lidiv_t result;
	// Checking division by zero
	if (secondNum == LongInt(0)) {
		std::cout << "ERROR: Division by zero!\n";
		return {LongInt(0), LongInt(0)};
	}
	// Checking division by one
	if (secondNum.abs() == LongInt(1)) {
		if (secondNum.isPositive()) {
			return {firstNum, LongInt(0)};
		} else {
			result.quot = firstNum;
			result.quot._positive = false;
			result.rem = LongInt(0);
			return result;
		}
	}
	// If the divisor is bigger than divident (in absolute values)
	if (secondNum.abs() > firstNum.abs()) {
		return {LongInt(0), firstNum};
	}
	// If the divisor is equal to divident (in absolute values)
	if (secondNum.abs() == firstNum.abs()) {
		if (firstNum.isPositive() == secondNum.isPositive()) {
			return {LongInt(1), LongInt(0)};
		} else {
			return {LongInt(-1), LongInt(0)};
		}
	}
	// Checking if divisor is a 10 to some power
	isPowerOfTen_t secondInfo = LongInt::_isPowerOfTen(secondNum);
	// Algorithm
	if (secondInfo.isPowerOfTen) {
		// Division if secondNum is a 10 in some power
		result.rem._digits = std::vector<int>(firstNum._digits.begin(), firstNum._digits.begin() + secondInfo.power);
		result.quot._digits = std::vector<int>(firstNum._digits.begin() + secondInfo.power, firstNum._digits.end());
		// Checking signs
		result.quot._positive = (firstNum.isPositive() == secondNum.isPositive());
		result.rem._positive = firstNum.isPositive();
		result.rem._checkLeadingZeroes();
		result.rem._checkNegativeZero();
	} else {
		// General division
		result.rem = firstNum.abs();
		LongInt divisor = secondNum.abs();
		long long sizeDiff = firstNum.size() - secondNum.size();
		while (sizeDiff >= 0) {
			LongInt remStep = divisor * pow(LongInt(10), sizeDiff);
			while (result.rem >= remStep) {
				result.quot += pow(LongInt(10), sizeDiff);
				result.rem -= remStep;
			}
			sizeDiff--;
		}
		result.quot._positive = (firstNum.isPositive() == secondNum.isPositive());
		result.rem._positive = firstNum.isPositive();
	}
	return result;
}

/**
 * Calculate remainder of division of two LongInt numbers.
 *
 * @param firstNum Number to be devided.
 * @param secondNum Number by which we divide.
 * @return Remainder of dividing 'firstNum' by 'secondNum'.
 */
LongInt mod(const LongInt& firstNum, const LongInt& secondNum) {
	LongInt result;
	// If modulo zero
	if (secondNum.isZero()) {
		std::cout << "ERROR: Modulo zero is an undefined value!\n";
		return result;
	}
	// If modulo of zero
	if (firstNum.isZero()) {
		return firstNum;
	}
	// If no need for division
	if (firstNum.abs() < secondNum.abs()) {
		result = firstNum;
		if (firstNum.isPositive() != secondNum.isPositive()) {
			result += secondNum;
		}
		return result;
	} else {
		// If firstNum is bigger or equal to secondNum
		lidiv_t divResults = div(firstNum, secondNum);
		if (firstNum.isPositive() != secondNum.isPositive()) {
			divResults.rem += secondNum;
		}
		return divResults.rem;
	}
	return result;
}

/**
 * Calculate greatest common divisor of two LongInt numbers.
 *
 * @param firstNum First number to calculate gcd of.
 * @param secondNum Second number to calculate gcd of.
 * @return Greatest common divisor of 'firstNum' and 'secondNum'.
 */
LongInt gcd(const LongInt& firstNum, const LongInt& secondNum) {
	LongInt first = firstNum;
	LongInt second = secondNum;
	first._positive = true;
	second._positive = true;
	// If first is zero
	if (first.isZero()) {
		if (second.isZero()) {
			std::cout << "ERROR: Unable to find the greatest common divisor as both numbers are zero!\n";
			return LongInt(0);
		}
		return second;
	}
	// If second is zero
	if (second.isZero()) {
		return first;
	}
	// Algorithm
	while (!first.isZero() and !second.isZero()) {
		if (first > second) {
			first %= second;
		} else {
			second %= first;
		}
	}
	return first + second;
}

/**
 * Calculate least common multiple of two LongInt numbers.
 *
 * @param firstNum First number to calculate lcm of.
 * @param secondNum Second number to calculate lcm of.
 * @return Least common multiple of 'firstNum' and 'secondNum'.
 */
LongInt lcm(const LongInt& firstNum, const LongInt& secondNum) {
	LongInt first = firstNum;
	LongInt second = secondNum;
	first._positive = true;
	second._positive = true;
	// If one of the numbers is zero
	if (first.isZero() or second.isZero()) {
		return LongInt(0);
	}
	return first * second / gcd(first, second);
}

/**
 * Calculate factoirial of LongInt number.
 *
 * @param number Number to generates its factorial.
 * @return factorial of 'number'.
 */
LongInt factorial(const LongInt& number) {
	LongInt result(1);
	for (LongInt i = 1; i <= number; i++) {
		result *= i;
	}
	return result;
}

/**
 * Generates random LongInt number.
 *
 * @return random generated member of LongInt class.
 */
LongInt Random() {
	std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(100, 10000);

	LongInt randomNumber(distrib(gen));

	randomNumber = pow(randomNumber, 10);
	randomNumber = randomNumber << 2;
	randomNumber = pow(randomNumber, 20);
	randomNumber = randomNumber >> 1;

	if (distrib(gen) % 2 == 1)
	{
		randomNumber *= -1;
	}

	std::cout << randomNumber << std::endl;
	return randomNumber;
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIB_H