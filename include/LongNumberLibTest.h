// This header contains tests for LongNumberLib

#ifndef LONGNUMBERLIBTEST_H
#define LONGNUMBERLIBTEST_H

#include "LongNumberLib.h"

// Opening namespace "LNL" (short for "LongNumberLib")
namespace LNL {

// A class for testing LongInt class
class Test {
private:
	static int totalTestNum; // Total number of tests
	static int failedTestNum; // Number of failed tests
public:
	template <typename T1, typename T2> 
	static bool verify(std::string testName, T1 recieved, T2 expected); // Custom assert function
	static int getTotal(); // Get total number of tests
	static int getFailed(); // Get number of failed tests
	static void resetTestNum(); // Reset test counter
	static void runAllTests(); // Run all tests
	static void printTestReport(); // Print out tests report
	static void test_constructor(); // Test constructor
	static void test_getString(); // Test getString() function
	static void test_isEqual(); // Test operator "==" and isEqual() function
	static void test_isNotEqual(); // Test operator "!=" and isNotEqual() function
	static void test_isGreater(); // Test operator ">" and isGreater() function
	static void test_isGreaterOrEqual(); // Test operator ">=" and isGreaterOrEqual() function
	static void test_isLess(); // Test operator "<" and isLess() function
	static void test_isLessOrEqual(); // Test operator "<=" and isLessOrEqual() function
	static void test_sum(); // Test operator "+" and sum function
};

int Test::totalTestNum = 0; // Total number of tests
int Test::failedTestNum = 0; // Number of failed tests

// Something like a custom assert function
// Verifies if recieved value matches expected value
template <typename T1, typename T2>
bool Test::verify(std::string testName, T1 recieved, T2 expected) {
	totalTestNum++;
	if (recieved == expected) {
		return true;
	} else {
		failedTestNum++;
		std::cout << "FAILED: " << testName << "\n";
		return false;
	}
}

// Get total number of tests
int Test::getTotal() {
	return totalTestNum;
}

// Get number of failed tests
int Test::getFailed() {
	return failedTestNum;
}

// Reset test counter
void Test::resetTestNum() {
	totalTestNum = 0;
	failedTestNum = 0;
}

// Run all tests
void Test::runAllTests() {
	test_constructor();
	test_getString();
	test_isEqual();
	test_isNotEqual();
	test_isGreater();
	test_isGreaterOrEqual();
	test_isLess();
	test_isLessOrEqual();
	test_sum();
}

// Print out test report
void Test::printTestReport() {
	std::cout << "\nTEST REPORT\n";
	std::cout << "Total tests:  " << totalTestNum << "\n";
	std::cout << "Failed tests: " << failedTestNum << "\n";
	if (failedTestNum == 0) {
		std::cout << "\nALL TESTS PASSED CORRECTLY\n";
	}
}

// Test constructors
void Test::test_constructor() {
	verify("constructor #1", LongInt("-0"), LongInt("0"));
	verify("constructor #2", LongInt("0"), LongInt("0"));
	verify("constructor #3", LongInt("000123"), LongInt("123"));
	verify("constructor #4", LongInt("-000123"), LongInt("-123"));
	verify("constructor #5", LongInt("1234someword56789"), LongInt("0"));
	verify("constructor #6", LongInt("-someword123456789"), LongInt("0"));
}

// Test getString() function
void Test::test_getString() {
	verify("getString #1", LongInt("0").getString(), "0");
	verify("getString #2", LongInt("-0").getString(), "0");
	verify("getString #3", LongInt("123456789").getString(), "123456789");
	verify("getString #4", LongInt("0123456789").getString(), "123456789");
	verify("getString #5", LongInt("-123456789").getString(), "-123456789");
	verify("getString #6", LongInt("000000000000123").getString(), "123");
	verify("getString #7", LongInt("-000000000000123").getString(), "-123");
	verify("getString #8", LongInt("00000000000010203").getString(), "10203");
	verify("getString #9", LongInt("-00000000000010203").getString(), "-10203");
	verify("getString #10", LongInt("-123000000000").getString(), "-123000000000");
}

// Test operator "==" and isEqual() function
void Test::test_isEqual() {
	verify("isEqual #1", LongInt("0") == LongInt("-0"), true);
	verify("isEqual #2", LongInt("0") == LongInt("0"), true);
	verify("isEqual #3", LongInt("0") == LongInt("1"), false);
	verify("isEqual #4", LongInt("123456789") == LongInt("123456789"), true);
	verify("isEqual #5", LongInt("123456789") == LongInt("-123456789"), false);
}

// Test operator "!=" and isNotEqual() function
void Test::test_isNotEqual() {
	verify("isNotEqual #1", LongInt("0") != LongInt("-0"), false);
	verify("isNotEqual #2", LongInt("0") != LongInt("-0"), true);
	verify("isNotEqual #3", LongInt("0") != LongInt("1"), true);
	verify("isNotEqual #4", LongInt("123456789") != LongInt("123456789"), false);
	verify("isNotEqual #5", LongInt("123456789") != LongInt("-123456789"), true);
}

// Test operator ">" and isGreater() function
void Test::test_isGreater() {
	verify("isGreater #1", LongInt("0") > LongInt("-0"), false);
	verify("isGreater #2", LongInt("1") > LongInt("0"), true);
	verify("isGreater #3", LongInt("1") > LongInt("-1"), true);
	verify("isGreater #4", LongInt("1") > LongInt("1"), false);
	verify("isGreater #5", LongInt("-99") > LongInt("-98"), false);
	verify("isGreater #6", LongInt("-98") > LongInt("-99"), true);
	verify("isGreater #7", LongInt("-123456789") > LongInt("123456789"), false);
	verify("isGreater #8", LongInt("123456789") > LongInt("123456789"), false);
}

// Test operator ">=" and isGreaterOrEqual() function
void Test::test_isGreaterOrEqual() {
	verify("isGreaterOrEqual #1", LongInt("0") >= LongInt("-0"), true);
	verify("isGreaterOrEqual #2", LongInt("1") >= LongInt("0"), true);
	verify("isGreaterOrEqual #3", LongInt("1") >= LongInt("-1"), true);
	verify("isGreaterOrEqual #4", LongInt("1") >= LongInt("1"), true);
	verify("isGreaterOrEqual #5", LongInt("-99") >= LongInt("-98"), false);
	verify("isGreaterOrEqual #6", LongInt("-98") >= LongInt("-99"), true);
	verify("isGreaterOrEqual #7", LongInt("-123456789") >= LongInt("123456789"), false);
	verify("isGreaterOrEqual #8", LongInt("123456789") >= LongInt("123456789"), true);
}

// Test operator "<" and isLess() function
void Test::test_isLess() {
	verify("isLess #1", LongInt("0") < LongInt("-0"), false);
	verify("isLess #2", LongInt("1") < LongInt("0"), false);
	verify("isLess #3", LongInt("1") < LongInt("-1"), false);
	verify("isLess #4", LongInt("1") < LongInt("1"), false);
	verify("isLess #5", LongInt("-99") < LongInt("-98"), true);
	verify("isLess #6", LongInt("-98") < LongInt("-99"), false);
	verify("isLess #7", LongInt("-123456789") < LongInt("123456789"), true);
	verify("isLess #8", LongInt("123456789") < LongInt("123456789"), false);
}

// Test operator "<=" and isLessOrEqual() function
void Test::test_isLessOrEqual() {
	verify("isLessOrEqual #1", LongInt("0") <= LongInt("-0"), true);
	verify("isLessOrEqual #2", LongInt("1") <= LongInt("0"), false);
	verify("isLessOrEqual #3", LongInt("1") <= LongInt("-1"), false);
	verify("isLessOrEqual #4", LongInt("1") <= LongInt("1"), true);
	verify("isLessOrEqual #5", LongInt("-99") <= LongInt("-98"), true);
	verify("isLessOrEqual #6", LongInt("-98") <= LongInt("-99"), false);
	verify("isLessOrEqual #7", LongInt("-123456789") <= LongInt("123456789"), true);
	verify("isLessOrEqual #8", LongInt("123456789") <= LongInt("123456789"), true);
}

// Test operator "+" and sum() function
void Test::test_sum() {
	verify("sum #1", LongInt("0") + LongInt("0"), LongInt("0"));
	verify("sum #2", LongInt("100") + LongInt("100"), LongInt("200"));
	verify("sum #3", LongInt("100") + LongInt("-100"), LongInt("0"));
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIBTEST_H