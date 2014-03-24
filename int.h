
#ifndef __INT_H__
#define __INT_H__

#include "variable.h"

class Int : public Variable
{
	public:
		Int(const string & name);

		virtual ~Int();
};

#endif
