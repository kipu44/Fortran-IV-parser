
#ifndef __CONSTANT_H__
#define __CONSTANT_H__

#include "aritmeticExpression.h"

class Constant : public AritmeticExpression
{
	public:
		Constant();

		virtual ~Constant();

		virtual string toCPlusPlus() = 0;

		virtual string toFortran() = 0;
};

#endif
