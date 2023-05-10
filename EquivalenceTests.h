// EquivalenceTests.h

#include <iostream>
#include "Addition.h"

class EquivalenceTests {
public:
    void runTests() {
        testPositiveIntegers();
        testNegativeIntegers();
        testMixtureIntegers();
        testZeroes();
        testBigPositiveIntegers();
        testBigNegativeIntegers();
        testSpecialCaseOne();
        testSpecialCaseMinusOne();
    }

private:
    void testPositiveIntegers() {
        Addition addition;
        if (addition.add(5, 10) != 15) {
            std::cout << "Test Positive Integers failed!" << std::endl;
        }
    }

    void testNegativeIntegers() {
        Addition addition;
        if (addition.add(-4, -5) != -9) {
            std::cout << "Test Negative Integers failed!" << std::endl;
        }
    }

    void testMixtureIntegers() {
        Addition addition;
        if (addition.add(4, -5) != -1) {
            std::cout << "Test Mixture Integers failed!" << std::endl;
        }
    }

    void testZeroes() {
        Addition addition;
        if (addition.add(0, 0) != 0) {
            std::cout << "Test Zeroes failed!" << std::endl;
        }
    }

    void testBigPositiveIntegers() {
        Addition addition;
        if (addition.add(100000, 200000) != 300000) {
            std::cout << "Test Big Positive Integers failed!" << std::endl;
        }
    }

    void testBigNegativeIntegers() {
        Addition addition;
        if (addition.add(-100000, -200000) != -300000) {
            std::cout << "Test Big Negative Integers failed!" << std::endl;
        }
    }

    void testSpecialCaseOne() {
        Addition addition;
        if (addition.add(1, 0) != 1) {
            std::cout << "Test Special Case One failed!" << std::endl;
        }
    }

    void testSpecialCaseMinusOne() {
        Addition addition;
        if (addition.add(-1, 0) != -1) {
            std::cout << "Test Special Case Minus One failed!" << std::endl;
        }
    }
};
