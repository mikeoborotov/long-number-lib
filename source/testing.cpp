// Testing the LongNumberLib.h

#include <iostream>

#include "../include/LongNumberLib.h"

int main(int argc, char *argv[]) {
	std::cout << "Running tests:" << "\n\n";

	LongNumberLib::LongInt x;
	LongNumberLib::LongInt y;
	x.print();
	y.print();

	x.set("120");
	x.print();

	y.set("95");
	y.print();

	LongNumberLib::LongInt res;
	res.set(LongNumberLib::LongInt::sum(x, y));
	res.print();

	x.print();
	y.print();

	return 0;
}