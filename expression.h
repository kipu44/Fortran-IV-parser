
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>
#include <iostream>

using namespace std;

class Expression
{
	protected:
		static const bool trace = 0;

	public:
		Expression();

		virtual ~Expression();

		virtual string toCPlusPlus() = 0;

		virtual string toFortran() = 0;
};

#endif
