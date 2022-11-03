// Testing the LongNumberLib.h

#include "../include/LongNumberLib.h"
#include "../include/TestsForLNL.h"

int main(int argc, char *argv[]) {
	std::cout << "Running tests:" << "\n\n";

	LongNumberLib::LongInt a("120");
	LongNumberLib::LongInt b("95");

	LongNumberLib::LongInt x = a;
	LongNumberLib::LongInt y = b;

	x.print();
	y.print();

	x = "65";
	y = "20";

	// x.set("120");
	// x.print();

	// y.set("95");
	// y.print();

	LongNumberLib::LongInt res;
	// res.set(LongNumberLib::LongInt::diff(x, y));
	res.set(x + y);
	res.print();

	res.set(x - y);
	res.print();

	// areEqual() and isBigger() tests
	// std::cout << LongNumberLib::LongInt::isEqual(x, y) << "\n";
	// std::cout << LongNumberLib::LongInt::isGreater(x, y) << "\n";
	// std::cout << LongNumberLib::LongInt::isGreater(y, x) << "\n";

	// isEven() and isOdd() tests
	// std::cout << LongNumberLib::LongInt::isEven(x) << "\n";
	// std::cout << LongNumberLib::LongInt::isOdd(x) << "\n";
	// std::cout << LongNumberLib::LongInt::isEven(y) << "\n";
	// std::cout << LongNumberLib::LongInt::isOdd(y) << "\n";

	// set() tests
	// x.print();
	// x.set(y);
	// x.print();

	// x.print();
	// y.print();

	return 0;
}