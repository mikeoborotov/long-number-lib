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

	void _checkDigitOverflow(); // Correct digits if they are beyond 9
	static int _compare(LongInt firstNum, LongInt secondNum); // Compare numbers
	static LongInt _sumAux(LongInt biggerNum, LongInt smallerNum); // Auxiliary function

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
	// NEED TO ADD LETTER CHECK
	void set(std::string input); // Set number value with string 
	void set(LongInt input); // Set number value with LongInt

	static bool isEqual(LongInt firstNum, LongInt secondNum); // Is 1st number equal to 2nd?
	static bool isGreater(LongInt firstNum, LongInt secondNum); // Is 1st number greater than 2nd?
	static bool isGreaterOrEqual(LongInt firstNum, LongInt secondNum); // Is 1st number greater or equal to 2nd?
	static bool isLess(LongInt firstNum, LongInt secondNum); // Is 1st number less than 2nd?
	static bool isLessOrEqual(LongInt firstNum, LongInt secondNum); // Is 1st number less or equal to 2nd?

	void add(LongInt secondNum); // Add a number TODO
	static LongInt sum(LongInt firstNum, LongInt secondNum); // Sum of 2 numbers TODO

	void print(); // Print number, its size and sign (mainly for debug)
};

// Correct digits if they are beyond 9
void LongInt::_checkDigitOverflow() {
	for (long long i = 0; i < this->size() - 1; i++) {
		if (this->_digits[i] > 9) {
			this->_digits[i] -= 10;
			this->_digits[i + 1] += 1;
		}
	}
	if (this->_digits[this->size() - 1] > 9) {
		this->_digits[this->size() - 1] -= 10;
		this->_digits.push_back(1);
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

// Default constructor
LongInt::LongInt() {
	_digits.push_back(0); // Number is set to 0 by default
	_positive = true;
}

// Overloaded constructor (for string)
LongInt::LongInt(std::string input) {
	this->set(input);
}

// Default destructor
LongInt::~LongInt() {}

// Get number as a string
std::string LongInt::getString() {
	std::string output;
	for (const auto &digit: this->_digits) {
		output.push_back(digit + '0');
	}
	if (this->isNegative()) {
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
	return this->_digits.size();
}

// Get number size, synonym to size()
long long LongInt::length() {
	return this->_digits.size();
}

// Is number even?
bool LongInt::isEven() {
	switch (this->_digits[0]) {
		case 0: return true;
		case 2: return true;
		case 4: return true;
		case 6: return true;
		case 8: return true;
		default: return false;
	}
}

// Is number odd?
bool LongInt::isOdd() {
	return !this->isEven();
}

// Is number positive?
bool LongInt::isPositive() {
	return this->_positive;
}

// Is number negative?
bool LongInt::isNegative() {
	return !this->_positive;
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

// // Is number negative?
static bool isNegative(LongInt number) {
	return number.isNegative();
}

// Set number value
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
	if (this->isPositive() and secondNum.isPositive()) {
		// TODO
	}
}

// Sum of 2 numbers
LongInt LongInt::sum(LongInt firstNum, LongInt secondNum) {
	LongInt result;

	if (firstNum.size() < secondNum.size()) {
		// TODO
	} else {
		result.set(firstNum.getString());
		// If (+,+) or (-,-)
		if (firstNum.isPositive() == secondNum.isPositive()) {
			for (long long i = 0; i < secondNum.size(); i++) {
				result._digits[i] += secondNum._digits[i];
			}
		}
		// If (+,-) or (-,+)
		if (firstNum.isPositive() != secondNum.isPositive()) {
			for (long long i = 0; i < secondNum.size(); i++) {
				result._digits[i] -= secondNum._digits[i];
			}
		}
	}

	

	result._checkDigitOverflow();
	return result;
}

// Print number, its size and sign (mostly for debug)
void LongInt::print() {
	std::cout << "Value: " << this->getString();
	std::cout << "\nSize:  " << this->size();
	std::cout << "\nSign:  ";
	if (this->isPositive()) {
		std::cout << "positive" << "\n\n";
	} else {
		std::cout << "negative" << "\n\n";
	}
}

} // Closing namespace "LongNumberLib"