// LongNumberLib is a library for long number arithmetics in C++

#pragma once

#include <iostream>
#include <vector>

// Opening namespace "LongNumberLib"
namespace LongNumberLib {

// A class for arbitrary length integers
class LongInt {
private:
	std::vector<int> _digits; // Number as a vector of digits
	bool _positive; // Is number positive?

public:
	LongInt();
	~LongInt();

	std::string getString(); // Get number value as a string
	long long size(); // Get number size
	bool isPositive(); // Is number positive?
	bool isNegative(); // Is number negative?
	void set(std::string input); // Set number value

	void print(); // Print number, its size and sign (mainly for debug)
};

// Default constructor
LongInt::LongInt() {
	_digits.push_back(0); // Number is set to 0 by default
	_positive = true;
}

// Default destructor
LongInt::~LongInt() {}

// Get number as a string
std::string LongInt::getString() {
	std::string output;
	for (const auto &digit: this->_digits) {
		output.push_back(digit + '0');
	}
	return output;
}

// Get number size
long long LongInt::size() {
	return this->_digits.size();
}

// Is number positive?
bool LongInt::isPositive() {
	return this->_positive;
}

// Is number negative?
bool LongInt::isNegative() {
	return !this->_positive;
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
}

// Print number, its size and sign (mostly for debug)
void LongInt::print() {
	std::cout << "Value: ";
	if (this->isNegative()) {
		std::cout << "-";
	}
	std::cout << this->getString();
	std::cout << "\nSize:  " << this->size();
	std::cout << "\nSign:  ";
	if (this->isPositive()) {
		std::cout << "+" << "\n\n";
	} else {
		std::cout << "-" << "\n\n";
	}
}

} // Closing namespace "LongNumberLib"