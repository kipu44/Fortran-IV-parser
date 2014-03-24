
#ifndef __ARITMETIC_IF_H__
#define __ARITMETIC_IF_H__

#include "aritmeticExpression.h"
#include "if.h"

class AritmeticIf : public If
{
	public:
		AritmeticIf(const string & text, const string & label);

		virtual ~AritmeticIf();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	protected:
		AritmeticExpression * expression;
};

#endif
