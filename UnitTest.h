#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include "Addition.h"

class UnitTest {
public:
    void runTests() {
        testAddition();
    }

private:
    void testAddition() {
        Addition addition;

        // Test 1: Adding two positive integers
        if (addition.add(2, 3) != 5) {
            std::cout << "Test 1 failed!" << std::endl;
        }

        // Test 2: Adding two negative integers
        if (addition.add(-2, -3) != -5) {
            std::cout << "Test 2 failed!" << std::endl;
        }

        // Test 3: Adding one positive and one negative integer
        if (addition.add(2, -3) != -1) {
            std::cout << "Test 3 failed!" << std::endl;
        }
    }
};

#endif
