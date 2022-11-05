// This header contains tests for LongNumberLib

#ifndef TESTLNL_H
#define TESTLNL_H

#include "LongNumberLib.h"

// Opening namespace "LNL" (short for "LongNumberLib")
namespace LNL {

int totalTestsNum = 0; // Total number of tests
int failedTestsNum = 0; // Number of failed tests

// Something like a custom assert function
// Checks if recieved value matches expected value
template <typename T1, typename T2>
bool test(std::string testName, T1 recieved, T2 expected) {
	totalTestsNum++;
	if (recieved == expected) {
		return true;
	} else {
		failedTestsNum++;
		std::cout << "FAILED: " << testName << "\n";
		return false;
	}
}


// Print out tests report
void printTestsReport() {
	std::cout << "\nTESTS REPORT\n";
	std::cout << "Total tests:  " << totalTestsNum << "\n";
	std::cout << "Failed tests: " << failedTestsNum << "\n";
}

// Test sum
void test_sum() {
	test("sum #1", 
		LongInt("0") + 
		LongInt("0"),
		LongInt("0"));
	test("sum #2", 
		LongInt("100") + 
		LongInt("100"),
		LongInt("200"));
	test("sum #3", 
		LongInt("100") + 
		LongInt("-100"),
		LongInt("0"));
}

// Run all tests
void runAllTests() {
	test_sum();
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // TESTLNL_H