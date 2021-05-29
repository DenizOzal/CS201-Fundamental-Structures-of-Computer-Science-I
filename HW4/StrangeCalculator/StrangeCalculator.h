#pragma once
#include "StackChar.h"
#include "StackDouble.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;

string infix2prefix(const string exp);
double evaluatePrefix(const string exp);
bool isBalancedInfix(const string exp);
void evaluateInputPrefixExpression();
int precedence(const char ch);
string reverseString(const string exp);

class StrangeCalculator {

};


