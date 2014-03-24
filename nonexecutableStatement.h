
#ifndef __NONEXECUTABLE_STATEMENT_H__
#define __NONEXECUTABLE_STATEMENT_H__

#include "statement.h"

class NonexecutableStatement : public Statement
{
	public:
		NonexecutableStatement(const string & label);

		virtual ~NonexecutableStatement();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;
};

#endif
