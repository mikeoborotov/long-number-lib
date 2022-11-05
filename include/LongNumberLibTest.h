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
	static bool test(std::string testName, T1 recieved, T2 expected); // Custom assert function
	static void runAllTests(); // Run all tests
	static void printTestReport(); // Print out tests report
	static void test_sum(); // Test sum
};

int Test::totalTestsNum = 0; // Total number of tests
int Test::failedTestsNum = 0; // Number of failed tests

// Something like a custom assert function
// Checks if recieved value matches expected value
template <typename T1, typename T2>
bool Test::test(std::string testName, T1 recieved, T2 expected) {
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
	test_sum();
}

// Print out tests report
void Test::printTestReport() {
	std::cout << "\nTEST REPORT\n";
	std::cout << "Total tests:  " << totalTestsNum << "\n";
	std::cout << "Failed tests: " << failedTestsNum << "\n";
}

// Test sum
void Test::test_sum() {
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

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIBTEST_H