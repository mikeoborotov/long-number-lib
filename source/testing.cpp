// Testing the LongNumberLib.h

#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"

int main(int argc, char *argv[]) {

	LNL::Test::runAllTests();
	LNL::Test::printTestReport();

	LNL::LongInt x("-1");
	x.print();
	--x;
	x.print();

	return 0;
}