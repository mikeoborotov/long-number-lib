// LongNumberLib is a library for long number arithmetics in C++

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// Opening namespace "LongNumberLib"
namespace LongNumberLib {

// A class for arbitrary length integers
class LongInt {
private:
	std::vector<int> _digits; // Number as a vector of digits
	bool _positive; // Is number positive?
	void _checkLeadingZeroes(); // Remove leading zeroes
	void _checkDigitOverflow(); // Correct digits if they are beyond 9 or below 0
	static int _compare(LongInt firstNum, LongInt secondNum); // Compare numbers
	static LongInt _sumAux(LongInt biggerNum, LongInt smallerNum); // Auxiliary function
	static LongInt _diffAux(LongInt biggerNum, LongInt smallerNum); // Auxiliary function
public:
	LongInt(); // Default constructor
	LongInt(std::string input); // Overloaded constructor (for string)
	~LongInt(); // Default destructor
	std::string getString(); // Get number value as a string
	LongInt abs(); // Get absolute number value
	long long size(); // Get number size
	long long length(); // Get number size
	bool isEven(); // Is number even?
	bool isOdd(); // Is number odd?
	bool isPositive(); // Is number positive?
	bool isNegative(); // Is number negative?
	static LongInt abs(LongInt number); // Get absolute number value
	static long long size(LongInt number); // Get number size
	static long long length(LongInt number); // Get number size
	static bool isEven(LongInt number); // Is number even?
	static bool isOdd(LongInt number); // Is number odd?
	static bool isPositive(LongInt number); // Is number positive?
	static bool isNegative(LongInt number); // Is number negative?
	void set(std::string input); // Set number value with string NEED TO ADD LETTER CHECK
	void set(LongInt input); // Set number value with LongInt
	static bool isEqual(LongInt firstNum, LongInt secondNum); // Is 1st number equal to 2nd?
	static bool isNotEqual(LongInt firstNum, LongInt secondNum); // Is 1st number not equal to 2nd?
	static bool isGreater(LongInt firstNum, LongInt secondNum); // Is 1st number greater than 2nd?
	static bool isGreaterOrEqual(LongInt firstNum, LongInt secondNum); // Is 1st number greater or equal to 2nd?
	static bool isLess(LongInt firstNum, LongInt secondNum); // Is 1st number less than 2nd?
	static bool isLessOrEqual(LongInt firstNum, LongInt secondNum); // Is 1st number less or equal to 2nd?
	void add(LongInt secondNum); // Add a number TODO
	LongInt operator +(LongInt secondNum); // Sum of 2 numbers
	LongInt operator -(LongInt secondNum); // Difference of 2 numbers
	static LongInt sum(LongInt firstNum, LongInt secondNum); // Sum of 2 numbers
	static LongInt diff(LongInt firstNum, LongInt secondNum);// Difference of 2 numbers
	void print(); // Print number, its size and sign (mainly for debug)
};

// Remove leading zeroes
void LongInt::_checkLeadingZeroes() {
	for (long long i = size() - 1; i > 0; i--) {
		if (_digits[i] == 0) {
			_digits.pop_back();
		} else {
			break;
		}
	}
}

// Correct digits if they are beyond 9 or below 0
void LongInt::_checkDigitOverflow() {
	for (long long i = 0; i < size() - 1; i++) {
		if (_digits[i] > 9) {
			_digits[i] -= 10;
			_digits[i + 1] += 1;
		} else if (_digits[i] < 0) {
			_digits[i] += 10;
			_digits[i + 1] -= 1;
		}
	}
	if (_digits[size() - 1] > 9) {
		_digits[size() - 1] -= 10;
		_digits.push_back(1);
	}
}

// Compare 2 LongInt numbers (1st relative to 2nd)
// Returns: 1 -> greater, 0 -> equal, -1 -> less
int LongInt::_compare(LongInt firstNum, LongInt secondNum) {
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

// Auxiliary function for sum()
// Sums 2 positive numbers (biggerNum >= smallerNum)
LongInt LongInt::_sumAux(LongInt biggerNum, LongInt smallerNum) {
	LongInt result;
	result.set(biggerNum);
	for (long long i = 0; i < smallerNum.size(); i++) {
		result._digits[i] += smallerNum._digits[i];
	}
	result._checkDigitOverflow();
	return result;
}

// Auxiliary function for sum()
// Finds the difference of 2 positive numbers (biggerNum >= smallerNum)
LongInt LongInt::_diffAux(LongInt biggerNum, LongInt smallerNum) {
	LongInt result;
	result.set(biggerNum);
	for (long long i = 0; i < smallerNum.size(); i++) {
		result._digits[i] -= smallerNum._digits[i];
	}
	result._checkDigitOverflow();
	result._checkLeadingZeroes();
	return result;
}

// Default constructor
LongInt::LongInt() {
	_digits.push_back(0); // Number is set to 0 by default
	_positive = true;
}

// Overloaded constructor (for string)
LongInt::LongInt(std::string input) {
	set(input);
}

// Default destructor
LongInt::~LongInt() {}

// Get number as a string
std::string LongInt::getString() {
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
LongInt LongInt::abs() {
	LongInt result;
	result.set(*this);
	result._positive = true;
	return result;
}

// Get number size
long long LongInt::size() {
	return _digits.size();
}

// Get number size, synonym to size()
long long LongInt::length() {
	return _digits.size();
}

// Is number even?
bool LongInt::isEven() {
	return (_digits[0] % 2 == 0);
}

// Is number odd?
bool LongInt::isOdd() {
	return !isEven();
}

// Is number positive?
bool LongInt::isPositive() {
	return _positive;
}

// Is number negative?
bool LongInt::isNegative() {
	return !_positive;
}

// Get absolute number value
LongInt LongInt::abs(LongInt number) {
	return number.abs();
}

// Get number size
long long LongInt::size(LongInt number) {
	return number.size();
}

// Get number size, synonym to size()
long long LongInt::length(LongInt number) {
	return number.length();
}

// Is number even?
bool LongInt::isEven(LongInt number) {
	return number.isEven();
}

// Is number odd?
bool LongInt::isOdd(LongInt number) {
	return number.isOdd();
}

// Is number positive?
bool LongInt::isPositive(LongInt number) {
	return number.isPositive();
}

// Is number negative?
static bool isNegative(LongInt number) {
	return number.isNegative();
}

// Set number value with string
void LongInt::set(std::string input) {
	this->_digits.erase(this->_digits.begin(), this->_digits.end());
	if (input.substr(0, 1) == "-") {
		this->_positive = false;
		input = input.substr(1, input.size());
	} else {
		this->_positive = true;
	}
	for (const auto &digit: input) {
		this->_digits.push_back(digit - '0');
	}
	std::reverse(_digits.begin(), _digits.end());
}

// Set number value with LongInt
void LongInt::set(LongInt input) {
	this->_digits = input._digits;
	this->_positive = input._positive;
}

// Is 1st number equal to 2nd?
bool LongInt::isEqual(LongInt firstNum, LongInt secondNum) {
	if ((firstNum.isPositive() != secondNum.isPositive()) or (firstNum.size() != secondNum.size())) {
		return false;
	}
	for (long long i = 0; i < firstNum.size(); i++) {
		if (firstNum._digits[i] != secondNum._digits[i]) {
			return false;
		}
	}
	return true;
}

// Is 1st number not equal to 2nd?
bool LongInt::isNotEqual(LongInt firstNum, LongInt secondNum) {
	return !LongInt::isEqual(firstNum, secondNum);
}

// Is 1st number greater than 2nd?
bool LongInt::isGreater(LongInt firstNum, LongInt secondNum) {
	switch(LongInt::_compare(firstNum, secondNum)) {
		case 1: return true; // Greater
		case 0: return false; // Equal
		case -1: return false; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is 1st number greater or equal to 2nd?
bool LongInt::isGreaterOrEqual(LongInt firstNum, LongInt secondNum) {
	switch(LongInt::_compare(firstNum, secondNum)) {
		case 1: return true; // Greater
		case 0: return true; // Equal
		case -1: return false; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Is 1st number less than 2nd?
bool LongInt::isLess(LongInt firstNum, LongInt secondNum) {
	switch(LongInt::_compare(firstNum, secondNum)) {
		case 1: return false; // Greater
		case 0: return false; // Equal
		case -1: return true; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is 1st number less or equal to 2nd?
bool LongInt::isLessOrEqual(LongInt firstNum, LongInt secondNum) {
	switch(LongInt::_compare(firstNum, secondNum)) {
		case 1: return false; // Greater
		case 0: return true; // Equal
		case -1: return true; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Add a number
void LongInt::add(LongInt secondNum) {
	// TODO
}

// Sum of 2 numbers
LongInt LongInt::operator +(LongInt secondNum) {
	return LongInt::sum(*this, secondNum);
}

// Difference of 2 numbers
LongInt LongInt::operator -(LongInt secondNum) {
	return LongInt::diff(*this, secondNum);
}

// Sum of 2 numbers
LongInt LongInt::sum(LongInt firstNum, LongInt secondNum) {
	LongInt result;
	if (firstNum.isPositive() and secondNum.isPositive()) {
		// If (+,+) or (-,-)
		if (LongInt::isGreaterOrEqual(firstNum, secondNum)) {
			result.set(_sumAux(firstNum, secondNum));
		} else {
			result.set(_sumAux(secondNum, firstNum));
		}
	} else if (firstNum.isPositive() and secondNum.isNegative()) {
		// If (+,-)
		if (LongInt::isGreaterOrEqual(firstNum, secondNum.abs())) {
			result.set(_diffAux(firstNum, secondNum.abs()));
		} else {
			result.set(_diffAux(secondNum.abs(), firstNum));
			result._positive = false;
		}
	} else {
		// If (-,+)
		if (LongInt::isGreaterOrEqual(firstNum.abs(), secondNum)) {
			result.set(_diffAux(firstNum.abs(), secondNum));
			result._positive = false;
		} else {
			result.set(_diffAux(secondNum, firstNum.abs()));
		}
	}
	return result;
}

// Difference of 2 numbers
LongInt LongInt::diff(LongInt firstNum, LongInt secondNum) {
	secondNum._positive = !secondNum.isPositive();
	return LongInt::sum(firstNum, secondNum);
}

// Print number, its size and sign (mostly for debug)
void LongInt::print() {
	std::cout << "Value: " << getString();
	std::cout << "\nSize:  " << size();
	std::cout << "\nSign:  ";
	if (isPositive()) {
		std::cout << "positive" << "\n\n";
	} else {
		std::cout << "negative" << "\n\n";
	}
}

} // Closing namespace "LongNumberLib"