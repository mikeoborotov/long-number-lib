// Copyright 2022 Mikhail Oborotov, Ivan Borisenkov, Elveg Khunshaev
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LNLUNITTESTS_H
#define LNLUNITTESTS_H

#include "LNL.h"

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
	static void test_toString(); // Test toString() function
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
	static void test_mult(); // Test operators *, *=
	static void test_quotient(); // Test operators /, /=
	static void test_remainder(); // Test operators %, %=
	static void test_unaryOperators(); // Test unary operators +, -, ++, --
	static void test_pow(); // Test pow() function
	static void test_mod(); // Test mod() function
	static void test_gcd(); // Test gcd() function
	static void test_lcm(); // Test lcm() function
	static void test_factorial(); // Test factorial() function
	static void test_shiftEncryption();
	static void test_boundRandom();
	static void test_modPowOfTwo();
	static void test_modPow();
	static void test_isMillerRabinPrime();
	static void test_randomPrime(int size);
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
		std::cout << "FAILED TEST: " << testName << "\n";
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
	std::cout << "\nRUNNING UNIT TESTS, DO NOT WORRY ABOUT ERROR MESSAGES\n\n";
	test_constructor();
	test_toString();
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
	test_mult();
	test_quotient();
	test_remainder();
	test_unaryOperators();
	test_pow();
	test_mod();
	test_gcd();
	test_lcm();
	test_factorial();
	test_shiftEncryption();
	test_modPowOfTwo();
	test_modPow();
	test_isMillerRabinPrime(); // This one usually takes some time
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
	verify("constructor #5", LongInt("1234someword56789"), LongInt("0")); // Testing error situation
	verify("constructor #6", LongInt("-someword123456789"), LongInt("0")); // Testing error situation
	verify("constructor #7", LongInt("-00000000000000000"), LongInt("0"));
	verify("constructor #8", toString(LongInt(short(0))), "0");
	verify("constructor #9", toString(LongInt(short(16))), "16");
	verify("constructor #10", toString(LongInt(short(-16))), "-16");
	verify("constructor #11", toString(LongInt(int(0))), "0");
	verify("constructor #12", toString(LongInt(int(16))), "16");
	verify("constructor #13", toString(LongInt(int(-16))), "-16");
	verify("constructor #14", toString(LongInt(long(0))), "0");
	verify("constructor #15", toString(LongInt(long(16))), "16");
	verify("constructor #16", toString(LongInt(long(-16))), "-16");
	verify("constructor #17", toString(LongInt((long long)int(0))), "0");
	verify("constructor #18", toString(LongInt((long long)int(16))), "16");
	verify("constructor #19", toString(LongInt((long long)int(-16))), "-16");
	verify("constructor #20", toString(LongInt((unsigned short)int(0))), "0");
	verify("constructor #21", toString(LongInt((unsigned short)int(16))), "16");
	verify("constructor #22", toString(LongInt((unsigned int)int(0))), "0");
	verify("constructor #23", toString(LongInt((unsigned int)int(16))), "16");
	verify("constructor #24", toString(LongInt((unsigned long)int(0))), "0");
	verify("constructor #25", toString(LongInt((unsigned long)int(16))), "16");
	verify("constructor #26", toString(LongInt((unsigned long long)int(0))), "0");
	verify("constructor #27", toString(LongInt((unsigned long long)int(16))), "16");
}

// Test toString() function
void Test::test_toString() {
	verify("getString #1", LongInt("0").toString(), "0");
	verify("getString #2", LongInt("-0").toString(), "0");
	verify("getString #3", LongInt("123456789").toString(), "123456789");
	verify("getString #4", LongInt("0123456789").toString(), "123456789");
	verify("getString #5", LongInt("-123456789").toString(), "-123456789");
	verify("getString #6", LongInt("000000000000123").toString(), "123");
	verify("getString #7", LongInt("-000000000000123").toString(), "-123");
	verify("getString #8", LongInt("00000000000010203").toString(), "10203");
	verify("getString #9", LongInt("-00000000000010203").toString(), "-10203");
	verify("getString #10", LongInt("-123000000000").toString(), "-123000000000");
}

// Test operator =
void Test::test_assignment() {
	verify("assignment #1", toString(LongInt() = short(0)), "0");
	verify("assignment #2", toString(LongInt() = short(5)), "5");
	verify("assignment #3", toString(LongInt() = short(-5)), "-5");
	verify("assignment #4", toString(LongInt() = int(0)), "0");
	verify("assignment #5", toString(LongInt() = int(5)), "5");
	verify("assignment #6", toString(LongInt() = int(-5)), "-5");
	verify("assignment #7", toString(LongInt() = long(0)), "0");
	verify("assignment #8", toString(LongInt() = long(5)), "5");
	verify("assignment #9", toString(LongInt() = long(-5)), "-5");
	verify("assignment #10", toString(LongInt() = (long long)int(0)), "0");
	verify("assignment #11", toString(LongInt() = (long long)int(5)), "5");
	verify("assignment #12", toString(LongInt() = (long long)int(-5)), "-5");
	verify("assignment #13", toString(LongInt() = (unsigned short)int(0)), "0");
	verify("assignment #14", toString(LongInt() = (unsigned short)int(5)), "5");
	verify("assignment #15", toString(LongInt() = (unsigned int)int(0)), "0");
	verify("assignment #16", toString(LongInt() = (unsigned int)int(5)), "5");
	verify("assignment #17", toString(LongInt() = (unsigned long)int(0)), "0");
	verify("assignment #18", toString(LongInt() = (unsigned long)int(5)), "5");
	verify("assignment #19", toString(LongInt() = (unsigned long long)int(0)), "0");
	verify("assignment #20", toString(LongInt() = (unsigned long long)int(5)), "5");
	verify("assignment #21", toString(LongInt() = "0"), "0");
	verify("assignment #22", toString(LongInt() = "-0"), "0");
	verify("assignment #23", toString(LongInt() = "12345678987654321"), "12345678987654321");
	verify("assignment #24", toString(LongInt() = "-12345678987654321"), "-12345678987654321");
	verify("assignment #25", toString(LongInt() = "-000000123456789"), "-123456789");
	verify("assignment #26", toString(LongInt() = LongInt("0")), "0");
	verify("assignment #27", toString(LongInt() = LongInt("-0")), "0");
	verify("assignment #28", toString(LongInt() = LongInt("12345678987654321")), "12345678987654321");
	verify("assignment #29", toString(LongInt() = LongInt("-12345678987654321")), "-12345678987654321");
	verify("assignment #30", toString(LongInt() = LongInt("-000000123456789")), "-123456789");
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
	verify("max/min #1", max(LongInt("0"), LongInt("0")), LongInt("0"));
	verify("max/min #2", max(LongInt("1"), LongInt("2")), LongInt("2"));
	verify("max/min #3", max(LongInt("-321"), LongInt("123")), LongInt("123"));
	verify("max/min #4", max(LongInt("-999"), LongInt("-998")), LongInt("-998"));
	verify("max/min #5", max(LongInt("0"), LongInt("-12345")), LongInt("0"));
	verify("max/min #6", min(LongInt("0"), LongInt("0")), LongInt("0"));
	verify("max/min #7", min(LongInt("1"), LongInt("2")), LongInt("1"));
	verify("max/min #8", min(LongInt("-321"), LongInt("123")), LongInt("-321"));
	verify("max/min #9", min(LongInt("-999"), LongInt("-998")), LongInt("-999"));
	verify("max/min #10", min(LongInt("0"), LongInt("-12345")), LongInt("-12345"));
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

// Test operators *, *=
void Test::test_mult() {
	verify("mult #1", LongInt(123) * LongInt(10), LongInt(1230));
	verify("mult #2", LongInt(123) * LongInt(1000), LongInt(123000));
	verify("mult #3", LongInt(123) * LongInt(1000000), LongInt(123000000));
	verify("mult #4", LongInt(123) * LongInt(-1000000), LongInt(-123000000));
	verify("mult #5", LongInt(-123) * LongInt(1000000), LongInt(-123000000));
	verify("mult #6", LongInt(-123) * LongInt(-1000000), LongInt(123000000));
	verify("mult #7", LongInt(-123) * LongInt(1), LongInt(-123));
	verify("mult #8", LongInt(-123) * LongInt(-1), LongInt(123));
	verify("mult #9", LongInt(123) * LongInt(0), LongInt(0));
	verify("mult #10", LongInt(-123) * LongInt(0), LongInt(0));
	verify("mult #11", LongInt(0) * LongInt(123), LongInt(0));
	verify("mult #12", LongInt(0) * LongInt(-123), LongInt(0));
	verify("mult #13", LongInt(10) * LongInt(123), LongInt(1230));
	verify("mult #14", LongInt(1000) * LongInt(123), LongInt(123000));
	verify("mult #15", LongInt(1000000) * LongInt(123), LongInt(123000000));
	verify("mult #16", LongInt(-1000000) * LongInt(123), LongInt(-123000000));
	verify("mult #17", LongInt(1000000) * LongInt(-123), LongInt(-123000000));
	verify("mult #18", LongInt(-1000000) * LongInt(-123), LongInt(123000000));
	verify("mult #19", LongInt(2) * LongInt(3), LongInt(6));
	verify("mult #20", LongInt(123) * LongInt(789), LongInt(97047));
	verify("mult #21", LongInt(123) * LongInt(-789), LongInt(-97047));
	verify("mult #22", LongInt(-123) * LongInt(789), LongInt(-97047));
	verify("mult #23", LongInt(-123) * LongInt(-789), LongInt(97047));
	verify("mult #24", LongInt(6432) * LongInt(12345), LongInt(79403040));
	verify("mult #25", LongInt(12345) * LongInt(6432), LongInt(79403040));
	verify("mult #26", LongInt("123456789987654321123456789") * LongInt("987654321123456789987654321"), LongInt("121932632103337905905959456328608443662094193112635269"));
	verify("mult #27", LongInt("123456789987654321123456789") * LongInt("-987654321123456789987654321"), LongInt("-121932632103337905905959456328608443662094193112635269"));
	verify("mult #28", LongInt("-123456789987654321123456789") * LongInt("987654321123456789987654321"), LongInt("-121932632103337905905959456328608443662094193112635269"));
	verify("mult #29", LongInt("-123456789987654321123456789") * LongInt("-987654321123456789987654321"), LongInt("121932632103337905905959456328608443662094193112635269"));
	verify("mult #30", LongInt(123) *= LongInt(789), LongInt(97047));
	verify("mult #31", LongInt(123) *= LongInt(-789), LongInt(-97047));
	verify("mult #32", LongInt(-123) *= LongInt(789), LongInt(-97047));
	verify("mult #33", LongInt(-123) *= LongInt(-789), LongInt(97047));
	verify("mult #34", LongInt(6432) *= LongInt(12345), LongInt(79403040));
	verify("mult #35", LongInt(12345) *= LongInt(6432), LongInt(79403040));
	verify("mult #36", LongInt("123456789987654321123456789") *= LongInt("987654321123456789987654321"), LongInt("121932632103337905905959456328608443662094193112635269"));
	verify("mult #37", LongInt("123456789987654321123456789") *= LongInt("-987654321123456789987654321"), LongInt("-121932632103337905905959456328608443662094193112635269"));
	verify("mult #38", LongInt("-123456789987654321123456789") *= LongInt("987654321123456789987654321"), LongInt("-121932632103337905905959456328608443662094193112635269"));
	verify("mult #39", LongInt("-123456789987654321123456789") *= LongInt("-987654321123456789987654321"), LongInt("121932632103337905905959456328608443662094193112635269"));
}

// Test operators /, /=
void Test::test_quotient() {
	verify("quotient #1", LongInt(123) / LongInt(0), LongInt(0));
	verify("quotient #2", LongInt(123) / LongInt(1), LongInt(123));
	verify("quotient #3", LongInt(123) / LongInt(-1), LongInt(-123));
	verify("quotient #4", LongInt(1234) / LongInt(1000), LongInt(1));
	verify("quotient #5", LongInt(1234) / LongInt(100), LongInt(12));
	verify("quotient #6", LongInt(1234) / LongInt(10), LongInt(123));
	verify("quotient #7", LongInt(123456789) / LongInt(10000), LongInt(12345));
	verify("quotient #8", LongInt(123456789) / LongInt(-10000), LongInt(-12345));
	verify("quotient #9", LongInt(-123456789) / LongInt(10000), LongInt(-12345));
	verify("quotient #10", LongInt(-123456789) / LongInt(-10000), LongInt(12345));
	verify("quotient #11", LongInt(12345) / LongInt(123456789), LongInt(0));
	verify("quotient #12", LongInt(12345) / LongInt(-123456789), LongInt(0));
	verify("quotient #13", LongInt(-12345) / LongInt(123456789), LongInt(0));
	verify("quotient #14", LongInt(-12345) / LongInt(-123456789), LongInt(0));
	verify("quotient #15", LongInt(123) / LongInt(5), LongInt(24));
	verify("quotient #16", LongInt(123) / LongInt(-5), LongInt(-24));
	verify("quotient #17", LongInt(-123) / LongInt(-5), LongInt(24));
	verify("quotient #18", LongInt(-123) / LongInt(5), LongInt(-24));
	verify("quotient #19", LongInt(10) / LongInt(3), LongInt(3));
	verify("quotient #20", LongInt(-10) / LongInt(4), LongInt(-2));
	verify("quotient #21", LongInt(123456789) / LongInt(123), LongInt(1003713));
	verify("quotient #22", LongInt(123456789) / LongInt(12345), LongInt(10000));
	verify("quotient #23", LongInt(-12345678987654321) / LongInt(123456789), LongInt(-100000000));
	verify("quotient #24", LongInt(123456789) / LongInt(-987), LongInt(-125082));
	verify("quotient #25", LongInt(1000012) / LongInt(1000), LongInt(1000));
	verify("quotient #26", LongInt(-1000012) / LongInt(1000), LongInt(-1000));
	verify("quotient #27", LongInt(1000000) / LongInt(100), LongInt(10000));
	verify("quotient #28", LongInt(-1000000) / LongInt(100), LongInt(-10000));
}

// Test operators %, %=
void Test::test_remainder() {
	verify("remainder #1", LongInt(123) % LongInt(0), LongInt(0));
	verify("remainder #2", LongInt(123) % LongInt(1), LongInt(0));
	verify("remainder #3", LongInt(123) % LongInt(-1), LongInt(0));
	verify("remainder #4", LongInt(1234) % LongInt(1000), LongInt(234));
	verify("remainder #5", LongInt(1234) % LongInt(100), LongInt(34));
	verify("remainder #6", LongInt(1234) % LongInt(10), LongInt(4));
	verify("remainder #7", LongInt(123456789) % LongInt(10000), LongInt(6789));
	verify("remainder #8", LongInt(123456789) % LongInt(-10000), LongInt(6789));
	verify("remainder #9", LongInt(-123456789) % LongInt(10000), LongInt(-6789));
	verify("remainder #10", LongInt(-123456789) % LongInt(-10000), LongInt(-6789));
	verify("remainder #11", LongInt(12345) % LongInt(123456789), LongInt(12345));
	verify("remainder #12", LongInt(12345) % LongInt(-123456789), LongInt(12345));
	verify("remainder #13", LongInt(-12345) % LongInt(123456789), LongInt(-12345));
	verify("remainder #14", LongInt(-12345) % LongInt(-123456789), LongInt(-12345));
	verify("remainder #15", LongInt(123) % LongInt(5), LongInt(3));
	verify("remainder #16", LongInt(123) % LongInt(-5), LongInt(3));
	verify("remainder #17", LongInt(-123) % LongInt(-5), LongInt(-3));
	verify("remainder #18", LongInt(-123) % LongInt(5), LongInt(-3));
	verify("remainder #19", LongInt(10) % LongInt(3), LongInt(1));
	verify("remainder #20", LongInt(-10) % LongInt(4), LongInt(-2));
	verify("remainder #21", LongInt(123456789) % LongInt(123), LongInt(90));
	verify("remainder #22", LongInt(123456789) % LongInt(12345), LongInt(6789));
	verify("remainder #23", LongInt(-12345678987654321) % LongInt(123456789), LongInt(-87654321));
	verify("remainder #24", LongInt(123456789) % LongInt(-987), LongInt(855));
	verify("remainder #25", LongInt(1000012) % LongInt(1000), LongInt(12));
	verify("remainder #26", LongInt(-1000012) % LongInt(1000), LongInt(-12));
	verify("remainder #27", LongInt(1000000) % LongInt(100), LongInt(0));
	verify("remainder #28", LongInt(-1000000) % LongInt(100), LongInt(0));
}

// Test unary operators +, -, ++, --
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

// Test pow() function
void Test::test_pow() {
	verify("pow #1", pow(LongInt(10), LongInt(0)), LongInt(1));
	verify("pow #2", pow(LongInt(-10), LongInt(0)), LongInt(1));
	verify("pow #3", pow(LongInt(10), LongInt(1)), LongInt(10));
	verify("pow #4", pow(LongInt(10), LongInt(2)), LongInt(100));
	verify("pow #5", pow(LongInt(10), LongInt(3)), LongInt(1000));
	verify("pow #6", pow(LongInt(1000), LongInt(3)), LongInt(1000000000));
	verify("pow #7", pow(LongInt(-100), LongInt(3)), LongInt(-1000000));
	verify("pow #8", pow(LongInt(-100), LongInt(4)), LongInt(100000000));
	verify("pow #9", pow(LongInt(0), LongInt(123456789)), LongInt(0));
	verify("pow #10", pow(LongInt(1), LongInt(123456789)), LongInt(1));
	verify("pow #11", pow(LongInt(-1), LongInt(123456789)), LongInt(-1));
	verify("pow #12", pow(LongInt(-2), LongInt(0)), LongInt(1));
	verify("pow #13", pow(LongInt(-2), LongInt(1)), LongInt(-2));
	verify("pow #14", pow(LongInt(-2), LongInt(2)), LongInt(4));
	verify("pow #15", pow(LongInt(-2), LongInt(7)), LongInt(-128));
	verify("pow #16", pow(LongInt(-2), LongInt(10)), LongInt(1024));
	verify("pow #17", pow(LongInt(123), LongInt(10)), LongInt("792594609605189126649"));
	verify("pow #18", pow(LongInt(123), LongInt(32)), LongInt("7532923656948158115977791009617077340797226775839122176340459265921"));
	verify("pow #19", pow(LongInt(-123), LongInt(47)), LongInt("-168089365432861366649544350793392541075881428948402902169684248440774393337801463143123536109842547"));
	verify("pow #20", pow(LongInt(1525469906), LongInt(2)), LongInt("2327058434111648836"));
}

// Test mod() function
void Test::test_mod() {
	verify("mod #1", mod(LongInt(5), LongInt(16)), LongInt(5));
	verify("mod #2", mod(LongInt(5), LongInt(-16)), LongInt(-11));
	verify("mod #3", mod(LongInt(-5), LongInt(16)), LongInt(11));
	verify("mod #4", mod(LongInt(-5), LongInt(-16)), LongInt(-5));
	verify("mod #5", mod(LongInt(0), LongInt(16)), LongInt(0));
	verify("mod #6", mod(LongInt(0), LongInt(-16)), LongInt(0));
	verify("mod #7", mod(LongInt(16), LongInt(0)), LongInt(0));
	verify("mod #8", mod(LongInt(-16), LongInt(0)), LongInt(0));
	verify("mod #9", mod(LongInt(15), LongInt(27)), LongInt(15));
	verify("mod #10", mod(LongInt(15), LongInt(-27)), LongInt(-12));
	verify("mod #11", mod(LongInt(-15), LongInt(27)), LongInt(12));
	verify("mod #12", mod(LongInt(-15), LongInt(-27)), LongInt(-15));
	verify("mod #13", mod(LongInt(123), LongInt(17)), LongInt(4));
	verify("mod #14", mod(LongInt(123), LongInt(-17)), LongInt(-13));
	verify("mod #15", mod(LongInt(-123), LongInt(17)), LongInt(13));
	verify("mod #16", mod(LongInt(-123), LongInt(-17)), LongInt(-4));
	verify("mod #17", mod(LongInt(123456789), LongInt(987)), LongInt(855));
	verify("mod #18", mod(LongInt(123456789), LongInt(-987)), LongInt(-132));
	verify("mod #19", mod(LongInt(-123456789), LongInt(987)), LongInt(132));
	verify("mod #20", mod(LongInt(-123456789), LongInt(-987)), LongInt(-855));
}

// Test gcd() function
void Test::test_gcd() {
	verify("gcd #1", gcd(LongInt(0), LongInt(0)), LongInt(0));
	verify("gcd #2", gcd(LongInt(0), LongInt(12345)), LongInt(12345));
	verify("gcd #3", gcd(LongInt(0), LongInt(-12345)), LongInt(12345));
	verify("gcd #4", gcd(LongInt(12345), LongInt(0)), LongInt(12345));
	verify("gcd #5", gcd(LongInt(-12345), LongInt(0)), LongInt(12345));
	verify("gcd #6", gcd(LongInt(12345), LongInt(6789)), LongInt(3));
	verify("gcd #7", gcd(LongInt(12345), LongInt(-6789)), LongInt(3));
	verify("gcd #8", gcd(LongInt(-12345), LongInt(6789)), LongInt(3));
	verify("gcd #9", gcd(LongInt(-12345), LongInt(-6789)), LongInt(3));
	verify("gcd #10", gcd(LongInt(1024), LongInt(128)), LongInt(128));
	verify("gcd #11", gcd(LongInt(461952), LongInt(116298)), LongInt(18));
	verify("gcd #12", gcd(LongInt(7966496), LongInt(314080416)), LongInt(32));
	verify("gcd #13", gcd(LongInt(24826148), LongInt(45296490)), LongInt(526));
	verify("gcd #14", gcd(LongInt(24826148), LongInt(-1)), LongInt(1));
}

// Test lcm() function
void Test::test_lcm() {
	verify("lcm #1", lcm(LongInt(0), LongInt(0)), LongInt(0));
	verify("lcm #2", lcm(LongInt(0), LongInt(12345)), LongInt(0));
	verify("lcm #3", lcm(LongInt(0), LongInt(-12345)), LongInt(0));
	verify("lcm #4", lcm(LongInt(12345), LongInt(0)), LongInt(0));
	verify("lcm #5", lcm(LongInt(-12345), LongInt(0)), LongInt(0));
	verify("lcm #6", lcm(LongInt(123), LongInt(456)), LongInt(18696));
	verify("lcm #7", lcm(LongInt(123), LongInt(-456)), LongInt(18696));
	verify("lcm #8", lcm(LongInt(-123), LongInt(456)), LongInt(18696));
	verify("lcm #9", lcm(LongInt(-123), LongInt(-456)), LongInt(18696));
	verify("lcm #10", lcm(LongInt(456), LongInt(123)), LongInt(18696));
	verify("lcm #11", lcm(LongInt(456), LongInt(-123)), LongInt(18696));
	verify("lcm #12", lcm(LongInt(-456), LongInt(123)), LongInt(18696));
	verify("lcm #13", lcm(LongInt(-456), LongInt(-123)), LongInt(18696));
	verify("lcm #14", lcm(LongInt(32), LongInt(64)), LongInt(64));
	verify("lcm #15", lcm(LongInt(123456789), LongInt(987654321)), LongInt("13548070123626141"));
}

// Test factorial() function
void Test::test_factorial() {
	verify("factorial #1", factorial(LongInt(0)), LongInt(1));
	verify("factorial #2", factorial(LongInt(1)), LongInt(1));
	verify("factorial #3", factorial(LongInt(2)), LongInt(2));
	verify("factorial #4", factorial(LongInt(3)), LongInt(6));
	verify("factorial #5", factorial(LongInt(4)), LongInt(24));
	verify("factorial #6", factorial(LongInt(5)), LongInt(120));
	verify("factorial #7", factorial(LongInt(6)), LongInt(720));
	verify("factorial #8", factorial(LongInt(7)), LongInt(5040));
	verify("factorial #9", factorial(LongInt(8)), LongInt(40320));
	verify("factorial #10", factorial(LongInt(9)), LongInt(362880));
	verify("factorial #11", factorial(LongInt(10)), LongInt(3628800));
	verify("factorial #12", factorial(LongInt(20)), LongInt("2432902008176640000"));
	verify("factorial #13", factorial(LongInt(30)), LongInt("265252859812191058636308480000000"));
}

void Test::test_shiftEncryption() {
	int tests = 10;
	for (int i = 1; i <= tests; i++) {
		LongInt initial = random();
		LongInt msg = initial;
		int key = std::rand() % 10;

		shiftEncrypt(msg, key);
		shiftDecrypt(msg, key);
		verify("shiftEncryption #" + i, initial, msg);
	}
}

void Test::test_boundRandom() {
	int i;
	LNL::LongInt left;
	LNL::LongInt right;
	do {
		std::cin >> i >> left >> right;
		for (int j = 1; j <= i; j++) {
			std::cout << "Random number #" + std::to_string(j) << ' ' << LNL::random(left, right) << std::endl;
		}
	} while (i != 0);
}

void Test::test_modPowOfTwo() {
	verify("modPowTwo #1", modPowTwo(1, 100, 15), 1);
	verify("modPowTwo #2", modPowTwo(17, 20, 185), 86);
	verify("modPowTwo #3", modPowTwo(756382912846, 10, 8234823), 4085431);
}

void Test::test_modPow() {
	verify("modPow #1", modPow(2, 10, 15), 4);
	verify("modPow #2", modPow(2, 32, 2), 0);
	verify("modPow #3", modPow(123456, 1, 123456), 0);
	verify("modPow #4", modPow(17, 13, 14), 3);
	verify("modPow #5", modPow(32, 47, 85), 8);
}

void Test::test_isMillerRabinPrime() {
	verify("isMillerRabinPrime #1", LongInt(2).isMillerRabinPrime(), true);
	verify("isMillerRabinPrime #2", LongInt(15).isMillerRabinPrime(), false);
	verify("isMillerRabinPrime #3", LongInt(997).isMillerRabinPrime(), true);
	verify("isMillerRabinPrime #4", LongInt(9721).isMillerRabinPrime(), true);
	verify("isMillerRabinPrime #5", LongInt("258838267").isMillerRabinPrime(), false);
	verify("isMillerRabinPrime #6", LongInt(997 * 9721).isMillerRabinPrime(), false);
	verify("isMillerRabinPrime #7", LongInt("19134702400093278081449423917").isMillerRabinPrime(), true);
	verify("isMillerRabinPrime #8", LongInt("1066340417491710595814572169").isMillerRabinPrime(), true);
	verify("isMillerRabinPrime #9", (LongInt("1066340417491710595814572169") * LongInt("19134702400093278081449423917")).isMillerRabinPrime(), false);
}

void Test::test_randomPrime(int size) {
	for (int i = 0; i < 10; i++) {
		std::cout << randomPrime(size) << std::endl;
	}
}

} // Closing namespace "LNL" (short for "LongNumberLib")

#endif // LNLUNITTESTS_H