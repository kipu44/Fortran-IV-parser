
#ifndef __UTILS_H__
#define __UTILS_H__

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void trim(string & text);

void toLower(string & text);

bool startsWith(const string & text, const string & begin);

size_t opening(const string & text, const int & end);
size_t closure(const string & text, const int & begin);

string parsuj(string text);

#endif
