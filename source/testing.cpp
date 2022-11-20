#include "../include/LongNumberLib.h"
#include "../include/LongNumberLibTest.h"

int main(int argc, char *argv[]) {

	LNL::Test::runAllTests();
	LNL::Test::printTestReport();

	return 0;
}