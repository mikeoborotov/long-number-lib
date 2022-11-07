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
	static void test_assignment(); // Test operator =
	static void test_isEqual(); // Test operator ==
	static void test_isNotEqual(); // Test operator !=
	static void test_isGreater(); // Test operator >
	static void test_isGreaterOrEqual(); // Test operator >=
	static void test_isLess(); // Test operator <
	static void test_isLessOrEqual(); // Test operator <=
	static void test_max_min(); // Test max() and min() functions
	static void test_sum(); // Test operators +, +=
	static void test_diff(); // Test operators -, -=
	static void test_unaryOperators(); // Unary operators +, -, ++, --
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
	test_assignment();
	test_isEqual();
	test_isNotEqual();
	test_isGreater();
	test_isGreaterOrEqual();
	test_isLess();
	test_isLessOrEqual();
	test_max_min();
	test_sum();
	test_diff();
	test_unaryOperators();
}

// Print out test report
void Test::printTestReport() {
	std::cout << "\nTEST REPORT\n";
	std::cout << "Total tests:  " << totalTestNum << "\n";
	std::cout << "Failed tests: " << failedTestNum << "\n";
	if ((failedTestNum == 0) and (totalTestNum != 0)) {
		std::cout << "\nALL TESTS PASSED CORRECTLY\n";
	} else if (totalTestNum != 0) {
		std::cout << "\nSOME TESTS FAILED TO PASS\n";
	} else {
		std::cout << "\nNO TESTS EXECUTED\n";
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
	verify("constructor #7", LongInt("-00000000000000000"), LongInt("0"));
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

// Test operator =
void Test::test_assignment() {
	verify("assignment #1", LongInt::getString(LongInt() = short(0)), "0");
	verify("assignment #2", LongInt::getString(LongInt() = short(5)), "5");
	verify("assignment #3", LongInt::getString(LongInt() = short(-5)), "-5");
	verify("assignment #4", LongInt::getString(LongInt() = int(0)), "0");
	verify("assignment #5", LongInt::getString(LongInt() = int(5)), "5");
	verify("assignment #6", LongInt::getString(LongInt() = int(-5)), "-5");
	verify("assignment #7", LongInt::getString(LongInt() = long(0)), "0");
	verify("assignment #8", LongInt::getString(LongInt() = long(5)), "5");
	verify("assignment #9", LongInt::getString(LongInt() = long(-5)), "-5");
}

// Test operator ==
void Test::test_isEqual() {
	verify("isEqual #1", LongInt("0") == LongInt("-0"), true);
	verify("isEqual #2", LongInt("0") == LongInt("0"), true);
	verify("isEqual #3", LongInt("0") == LongInt("1"), false);
	verify("isEqual #4", LongInt("123456789") == LongInt("123456789"), true);
	verify("isEqual #5", LongInt("123456789") == LongInt("-123456789"), false);
}

// Test operator !=
void Test::test_isNotEqual() {
	verify("isNotEqual #1", LongInt("0") != LongInt("-0"), false);
	verify("isNotEqual #2", LongInt("0") != LongInt("0"), false);
	verify("isNotEqual #3", LongInt("0") != LongInt("1"), true);
	verify("isNotEqual #4", LongInt("123456789") != LongInt("123456789"), false);
	verify("isNotEqual #5", LongInt("123456789") != LongInt("-123456789"), true);
}

// Test operator >
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

// Test operator >=
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

// Test operator <
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

// Test operator <=
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

// Test max() and min() functions
void Test::test_max_min() {
	verify("max/min #1", LongInt::max(LongInt("0"), LongInt("0")), LongInt("0"));
	verify("max/min #2", LongInt::max(LongInt("1"), LongInt("2")), LongInt("2"));
	verify("max/min #3", LongInt::max(LongInt("-321"), LongInt("123")), LongInt("123"));
	verify("max/min #4", LongInt::max(LongInt("-999"), LongInt("-998")), LongInt("-998"));
	verify("max/min #5", LongInt::max(LongInt("0"), LongInt("-12345")), LongInt("0"));
	verify("max/min #6", LongInt::min(LongInt("0"), LongInt("0")), LongInt("0"));
	verify("max/min #7", LongInt::min(LongInt("1"), LongInt("2")), LongInt("1"));
	verify("max/min #8", LongInt::min(LongInt("-321"), LongInt("123")), LongInt("-321"));
	verify("max/min #9", LongInt::min(LongInt("-999"), LongInt("-998")), LongInt("-999"));
	verify("max/min #10", LongInt::min(LongInt("0"), LongInt("-12345")), LongInt("-12345"));
}

// Test operators +, +=
void Test::test_sum() {
	verify("sum #1", LongInt("0") + LongInt("0"), LongInt("0"));
	verify("sum #2", LongInt("100") + LongInt("100"), LongInt("200"));
	verify("sum #3", LongInt("100") + LongInt("-100"), LongInt("0"));
	verify("sum #4", LongInt("99") + LongInt("99"), LongInt("198"));
	verify("sum #5", LongInt("987654321") + LongInt("987654321"), LongInt("1975308642"));
	verify("sum #6", LongInt("0") += LongInt("0"), LongInt("0"));
	verify("sum #7", LongInt("100") += LongInt("100"), LongInt("200"));
	verify("sum #8", LongInt("100") += LongInt("-100"), LongInt("0"));
	verify("sum #9", LongInt("99") += LongInt("99"), LongInt("198"));
	verify("sum #10", LongInt("987654321") += LongInt("987654321"), LongInt("1975308642"));
}

// Test operators -, -=
void Test::test_diff() {
	verify("diff #1", LongInt("0") - LongInt("0"), LongInt("0"));
	verify("diff #2", LongInt("100") - LongInt("100"), LongInt("0"));
	verify("diff #3", LongInt("100") - LongInt("-100"), LongInt("200"));
	verify("diff #4", LongInt("999999999999") - LongInt("999999999998"), LongInt("1"));
	verify("diff #5", LongInt("1000000") - LongInt("2999999"), LongInt("-1999999"));
	verify("diff #6", LongInt("0") -= LongInt("0"), LongInt("0"));
	verify("diff #7", LongInt("100") -= LongInt("100"), LongInt("0"));
	verify("diff #8", LongInt("100") -= LongInt("-100"), LongInt("200"));
	verify("diff #9", LongInt("999999999999") -= LongInt("999999999998"), LongInt("1"));
	verify("diff #10", LongInt("1000000") -= LongInt("2999999"), LongInt("-1999999"));
	verify("diff #11", LongInt("-123") - LongInt("150"), LongInt("-273"));
	verify("diff #12", LongInt("-111111111111") - LongInt("222222222222"), LongInt("-333333333333"));
}

// Unary operators +, -, ++, --
void Test::test_unaryOperators() {
	verify("unary #1", +LongInt("0"), LongInt("0"));
	verify("unary #2", +LongInt("123"), LongInt("123"));
	verify("unary #3", +LongInt("-123"), LongInt("-123"));
	verify("unary #4", -LongInt("0"), LongInt("0"));
	verify("unary #5", -LongInt("123"), LongInt("-123"));
	verify("unary #6", -LongInt("-123"), LongInt("123"));
	verify("unary #7", ++LongInt("-1"), LongInt("0"));
	verify("unary #8", ++LongInt("0"), LongInt("1"));
	verify("unary #9", ++LongInt("1"), LongInt("2"));
	verify("unary #10", ++LongInt("99"), LongInt("100"));
	verify("unary #11", ++LongInt("-99"), LongInt("-98"));
	verify("unary #12", --LongInt("-2"), LongInt("-3"));
	verify("unary #13", --LongInt("-1"), LongInt("-2"));
	verify("unary #14", --LongInt("0"), LongInt("-1"));
	verify("unary #15", --LongInt("1"), LongInt("0"));
	verify("unary #16", --LongInt("99"), LongInt("98"));
	verify("unary #17", LongInt("-1")++, LongInt("0"));
	verify("unary #18", LongInt("0")++, LongInt("1"));
	verify("unary #19", LongInt("1")++, LongInt("2"));
	verify("unary #20", LongInt("99")++, LongInt("100"));
	verify("unary #21", LongInt("-99")++, LongInt("-98"));
	verify("unary #22", LongInt("-2")--, LongInt("-3"));
	verify("unary #23", LongInt("-1")--, LongInt("-2"));
	verify("unary #24", LongInt("0")--, LongInt("-1"));
	verify("unary #25", LongInt("1")--, LongInt("0"));
	verify("unary #26", LongInt("99")--, LongInt("98"));
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LONGNUMBERLIBTEST_H