//
// Created by Toby Dragon on 8/26/17.
//

#ifndef COMP220LAB_TESTLIB_H
#define COMP220LAB_TESTLIB_H

#include <string>

void printAssertEquals(int expected, int actual);

void printAssertBoolEquals(bool expected, bool actual);

void printAssertFloatEquals(bool expected, bool actual);

void printAssertCloseToEqual(float expected, float actual, float errorMargin);

void printAssertArrayEqual(int* expected, int* actual, int size);

void printAssertStringEqual(std::string expected, std::string actual);

bool checkSorted(int* a, int size);

bool checkForSameElements(const int* a1, const int* a2, int size);

#endif //COMP220LAB_TESTLIB_H

