
#ifndef __STOP_H__
#define __STOP_H__

#include "nonexecutableStatement.h"

class Stop : public NonexecutableStatement
{
	public:
		Stop(const string & label);

		virtual ~Stop();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);
};

#endif
