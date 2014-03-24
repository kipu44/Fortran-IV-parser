
#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#include "constant.h"

class Variable : public Constant
{
	public:
		Variable(const string & name);

		virtual ~Variable();

		virtual string toCPlusPlus() = 0;

		virtual string toFortran() = 0;

	protected:
		const string name;
};

#endif
