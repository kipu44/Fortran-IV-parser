
#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>

using namespace std;

class Expression
{
	public:
		Expression();

		virtual ~Expression();

		virtual string toCPlusPlus() = 0;

		virtual string toFortran() = 0;
};

#endif
