// LongNumberLib is a library for long number arithmetics in C++

#ifndef LONGNUMBERLIB_H
#define LONGNUMBERLIB_H

#include <iostream>
#include <vector>
#include <algorithm>

// Opening namespace "LNL" (short for "LongNumberLib")
namespace LNL {

// A class for arbitrary length integers
class LongInt {
private:
	std::vector<int> _digits; // Number as a vector of digits
	bool _positive; // Is number positive?
	void _checkLeadingZeroes(); // Remove leading zeroes
	void _checkDigitOverflow(); // Correct digits if they are beyond 9 or below 0
	void _checkNegativeZero(); // Correct -0 to 0
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
	bool isZero(); // Is number equal to 0?
	bool isOne(); // Is number equal to 1?
	bool isPositive(); // Is number positive?
	bool isNegative(); // Is number negative?
	static std::string getString(LongInt number); // Get number value as a string
	static LongInt abs(LongInt number); // Get absolute number value
	static long long size(LongInt number); // Get number size
	static long long length(LongInt number); // Get number size
	static bool isEven(LongInt number); // Is number even?
	static bool isOdd(LongInt number); // Is number odd?
	static bool isZero(LongInt number); // Is number equal to 0?
	static bool isOne(LongInt number); // Is number equal to 1?
	static bool isPositive(LongInt number); // Is number positive?
	static bool isNegative(LongInt number); // Is number negative?
	LongInt operator =(signed short input); // Set number value with short
	LongInt operator =(unsigned short input); // Set number value with unsigned short
	LongInt operator =(signed int input); // Set number value with int
	LongInt operator =(unsigned int input); // Set number value with unsigned int
	LongInt operator =(signed long input); // Set number value with long
	LongInt operator =(unsigned long input); // Set number value with unsigned long
	LongInt operator =(signed long long input); // Set number value with long long
	LongInt operator =(unsigned long long input); // Set number value with unsigned long long
	LongInt operator =(std::string input); // Set number value with string
	LongInt operator =(LongInt input); // Set number value with LongInt
	bool operator ==(LongInt secondNum); // Is this number equal to 2nd?
	bool operator !=(LongInt secondNum); // Is this number not equal to 2nd?
	bool operator >(LongInt secondNum); // Is this number greater than 2nd?
	bool operator >=(LongInt secondNum); // Is this number greater or equal to 2nd?
	bool operator <(LongInt secondNum); // Is this number less than 2nd?
	bool operator <=(LongInt secondNum); // Is this number less or equal to 2nd?
	static LongInt max(LongInt firstNum, LongInt secondNum); // Return max number
	static LongInt min(LongInt firstNum, LongInt secondNum); // Return min number
	LongInt operator +(LongInt secondNum); // Sum of 2 numbers
	LongInt operator -(LongInt secondNum); // Difference of 2 numbers
	LongInt operator +=(LongInt secondNum); // Add another number
	LongInt operator -=(LongInt secondNum); // Subtract another number
	LongInt operator +(); // Return this number (unary plus)
	LongInt operator ++(); // Add 1 to the number (prefix)
	LongInt operator ++(int); // Add 1 to the number (postfix)
	LongInt operator -(); // Return opposite sign number (unary minus)
	LongInt operator --(); // Subtract 1 from the number (prefix)
	LongInt operator --(int); // Subtract 1 to the number (postfix)
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

// Correct -0 to 0
void LongInt::_checkNegativeZero() {
	if (isZero()) {
		_positive = true;
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
	result = biggerNum;
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
	result = biggerNum;
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
	*this = input;
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
	result = *this;
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

// Is number equal to 0?
bool LongInt::isZero(){
	if ((size() == 1) and (_digits[0] == 0)) {
		return true;
	}
	return false;
}

// Is number equal to 1?
bool LongInt::isOne() {
	if ((size() == 1) and (_digits[0] == 1) and _positive) {
		return true;
	}
	return false;
}

// Is number positive?
bool LongInt::isPositive() {
	return _positive;
}

// Is number negative?
bool LongInt::isNegative() {
	return !_positive;
}

// Get number value as a string
std::string LongInt::getString(LongInt number) {
	return number.getString();
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

// Is number equal to 0?
bool LongInt::isZero(LongInt number){
	return number.isZero();
}

// Is number equal to 1?
bool LongInt::isOne(LongInt number) {
	return number.isOne();
}

// Is number positive?
bool LongInt::isPositive(LongInt number) {
	return number.isPositive();
}

// Is number negative?
static bool isNegative(LongInt number) {
	return number.isNegative();
}

// Set number value with short
LongInt LongInt::operator =(signed short input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned short
LongInt LongInt::operator =(unsigned short input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with int
LongInt LongInt::operator =(signed int input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned int
LongInt LongInt::operator =(unsigned int input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with long
LongInt LongInt::operator =(signed long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned long
LongInt LongInt::operator =(unsigned long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with long long
LongInt LongInt::operator =(signed long long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with unsigned long long
LongInt LongInt::operator =(unsigned long long input) {
	*this = std::to_string(input);
	return *this;
}

// Set number value with string
LongInt LongInt::operator =(std::string input) {
	_digits.erase(_digits.begin(), _digits.end());
	if (input.substr(0, 1) == "-") {
		_positive = false;
		input = input.substr(1, input.size());
	} else {
		_positive = true;
	}
	for (const auto &digit: input) {
		// In case of a non-digit character
		if ((digit < 48) or (digit > 57)) {
			*this = "0";
			std::cout << "ERROR: A non-digit character \"" << digit;
			std::cout << "\" is encountered when assigning a value of a LongInt with a string.";
			std::cout << " Value is set to 0 by default.\n";
			return *this;
		}
		_digits.push_back(digit - '0');
	}
	std::reverse(_digits.begin(), _digits.end());
	_checkLeadingZeroes();
	_checkNegativeZero();
	return *this;
}

// Set number value with LongInt
LongInt LongInt::operator =(LongInt input) {
	_digits.erase(_digits.begin(), _digits.end());
	_digits = input._digits;
	_positive = input._positive;
	return *this;
}

// Is this number equal to 2nd?
bool LongInt::operator ==(LongInt secondNum) {
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
bool LongInt::operator !=(LongInt secondNum) {
	return !(*this == secondNum);
}

// Is this number greater than 2nd?
bool LongInt::operator >(LongInt secondNum) {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return true; // Greater
		case 0: return false; // Equal
		case -1: return false; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is this number greater or equal to 2nd?
bool LongInt::operator >=(LongInt secondNum) {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return true; // Greater
		case 0: return true; // Equal
		case -1: return false; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Is this number less than 2nd?
bool LongInt::operator <(LongInt secondNum) {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return false; // Greater
		case 0: return false; // Equal
		case -1: return true; // Less
	}
	return false; // Duplicating '0' case to avoid warning
}

// Is this number less or equal to 2nd?
bool LongInt::operator <=(LongInt secondNum) {
	switch(LongInt::_compare(*this, secondNum)) {
		case 1: return false; // Greater
		case 0: return true; // Equal
		case -1: return true; // Less
	}
	return true; // Duplicating '0' case to avoid warning
}

// Return max number
LongInt LongInt::max(LongInt firstNum, LongInt secondNum) {
	if (firstNum >= secondNum) {
		return firstNum;
	}
	return secondNum;
}

// Return min number
LongInt LongInt::min(LongInt firstNum, LongInt secondNum) {
	if (firstNum <= secondNum) {
		return firstNum;
	}
	return secondNum;
}

// Sum of 2 numbers
LongInt LongInt::operator +(LongInt secondNum) {
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
LongInt LongInt::operator -(LongInt secondNum) {
	secondNum._positive = !secondNum.isPositive();
	return *this + secondNum;
}

// Add another number
LongInt LongInt::operator +=(LongInt secondNum) {
	return *this = *this + secondNum;
}

// Subtract another number
LongInt LongInt::operator -=(LongInt secondNum) {
	return *this = *this - secondNum;
}

// Return this number (unary plus)
LongInt LongInt::operator +() {
	return *this;
}

// Add 1 to the number (prefix)
LongInt LongInt::operator ++() {
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
LongInt LongInt::operator --() {
	return *this = *this - LongInt("1");
}

// Subtract 1 to the number (postfix)
LongInt LongInt::operator --(int) {
	return *this = *this - LongInt("1");
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

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIB_H