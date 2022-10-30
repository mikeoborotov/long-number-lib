// Testing the LongNumberLib.h

#include <iostream>

#include "../include/LongNumberLib.h"

int main(int argc, char *argv[]) {
	std::cout << "Running tests" << "\n";

	LongNumberLib::LongInt x;
	x.print();

	x.set("45");
	x.print();

	x.set("-120");
	x.print();

	x.set("-123987");
	x.print();

	return 0;
}