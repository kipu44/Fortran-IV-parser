
#ifndef __ARITMETIC_EXPRESSION_H__
#define __ARITMETIC_EXPRESSION_H__

#include "expression.h"

class AritmeticExpression : public Expression
{
	private:
		static const bool trace = Expression::trace;

	public:
		AritmeticExpression(const string & text);
		virtual ~AritmeticExpression();

		virtual string toCPlusPlus();

		virtual string toFortran();

	protected:
		string text;
};

#endif
