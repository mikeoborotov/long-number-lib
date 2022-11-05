// Testing the LongNumberLib.h

#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"

int main(int argc, char *argv[]) {

	LNL::runAllTests();
	LNL::printTestsReport();

	return 0;
}