
#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <vector>
#include <string>
#include <iostream>

typedef std::pair<std::string, bool (*)()> TestCase;

void printResults(bool pass);
void runAll(std::vector< TestCase > & testCases);

#endif

