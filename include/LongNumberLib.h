// LongNumberLib is a library for long number arithmetics in C++

#pragma once

#include <iostream>

// A class for arbitrary length integers
class LongInt {
private:
	std::string _value; // Number as a string
	size_t _size; // Number length
	bool _negative; // Is number negative?

public:
	LongInt();
	~LongInt();

	std::string get(); // Get number value as a string
	size_t getSize(); // Get number size
	bool isNegative(); // Is number negative?
	void set(std::string input); // Set number value

	void print(); // Print number, its size and sign (mainly for debug)
};

LongInt::LongInt() {
	_value = "0"; // Value set to 0 by default
	_size = 1;
	_negative = false;
}

LongInt::~LongInt() {}

// Get number value as a string
std::string LongInt::get() {
	return this->_value;
}

// Get number size
size_t LongInt::getSize() {
	return this->_size;
}

// Is number negative?
bool LongInt::isNegative() {
	return this->_negative;
}

// Set number value
void LongInt::set(std::string input) {
	this->_value = input;
	this->_size = input.length();
	if (input.substr(0, 1) == "-") {
		this->_negative = true;
	} else {
		this->_negative = false;
	}
}

// Print number, its size and sign (mainly for debug)
void LongInt::print() {
	std::cout << "Value: " << this->_value << "\n";
	std::cout << "Size:  " << this->_size << "\n";
	std::cout << "Sign:  ";
	if (_negative) {
		std::cout << "-" << "\n\n";
	} else {
		std::cout << "+" << "\n\n";
	}
}