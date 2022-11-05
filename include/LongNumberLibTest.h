// This header contains tests for LongNumberLib

#ifndef LONGNUMBERLIBTEST_H
#define LONGNUMBERLIBTEST_H

#include "LongNumberLib.h"

// Opening namespace "LNL" (short for "LongNumberLib")
namespace LNL {

// A class for testing LongInt class
class Test {
private:
	static int totalTestsNum; // Total number of tests
	static int failedTestsNum; // Number of failed tests
public:
	template <typename T1, typename T2> 
	static bool verify(std::string testName, T1 recieved, T2 expected); // Custom assert function
	static void runAllTests(); // Run all tests
	static void printTestReport(); // Print out tests report
	static void test_constructor(); // Test constructor
	static void test_getString(); // Test getString() function
	static void test_sum(); // Test sum function
};

int Test::totalTestsNum = 0; // Total number of tests
int Test::failedTestsNum = 0; // Number of failed tests

// Something like a custom assert function
// Verifies if recieved value matches expected value
template <typename T1, typename T2>
bool Test::verify(std::string testName, T1 recieved, T2 expected) {
	totalTestsNum++;
	if (recieved == expected) {
		return true;
	} else {
		failedTestsNum++;
		std::cout << "FAILED: " << testName << "\n";
		return false;
	}
}

// Run all tests
void Test::runAllTests() {
	test_constructor();
	test_getString();
	test_sum();
}

// Print out test report
void Test::printTestReport() {
	std::cout << "\nTEST REPORT\n";
	std::cout << "Total tests:  " << totalTestsNum << "\n";
	std::cout << "Failed tests: " << failedTestsNum << "\n";
}

// Test constructors
void Test::test_constructor() {
	verify("constructor #1", LongInt("0"), LongInt("-0"));
}

// Test getString() function
void Test::test_getString() {
	verify("getString #1", LongInt("0").getString(), "0");
	verify("getString #2", LongInt("-0").getString(), "0");
	verify("getString #3", LongInt("123456789").getString(), "123456789");
	verify("getString #4", LongInt("0123456789").getString(), "123456789");
	verify("getString #5", LongInt("-123456789").getString(), "-123456789");
}

// Test sum() function
void Test::test_sum() {
	verify("sum #1", LongInt("0") + LongInt("0"), LongInt("0"));
	verify("sum #2", LongInt("100") + LongInt("100"), LongInt("200"));
	verify("sum #3", LongInt("100") + LongInt("-100"), LongInt("0"));
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIBTEST_H