// Testing the LongNumberLib.h

#include "../include/LongNumberLib.h"
#include "../include/TestLNL.h"

int main(int argc, char *argv[]) {

	TestLNL::runAllTests();
	TestLNL::printTestsReport();

	return 0;
}