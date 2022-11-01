// Testing the LongNumberLib.h

#include <iostream>

#include "../include/LongNumberLib.h"

int main(int argc, char *argv[]) {
	std::cout << "Running tests:" << "\n\n";

	LongNumberLib::LongInt x("120");
	LongNumberLib::LongInt y("95");
	x.print();
	y.print();

	// x.set("120");
	// x.print();

	// y.set("95");
	// y.print();

	LongNumberLib::LongInt res;
	res.set(LongNumberLib::LongInt::sum(x, y));
	res.print();

	// areEqual() and isBigger() tests
	// std::cout << LongNumberLib::LongInt::areEqual(x, y) << "\n";
	// std::cout << LongNumberLib::LongInt::isBigger(x, y) << "\n";
	// std::cout << LongNumberLib::LongInt::isBigger(y, x) << "\n";

	// x.print();
	// y.print();

	return 0;
}