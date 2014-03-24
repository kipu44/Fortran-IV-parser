
#ifndef __END_H__
#define __END_H__

#include "nonexecutableStatement.h"

class End : public NonexecutableStatement
{
	public:
		End(const string & label);

		virtual ~End();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);
};

#endif
