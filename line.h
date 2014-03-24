
#ifndef __LINE_H__
#define __LINE_H__

#include <iostream>
#include <string>

using namespace std;

class Line
{
	public:
		static const bool trace = 0;
		static const bool debug = 0;

		Line();

		virtual ~Line();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;
};

#endif
