
#ifndef __EXECUTABLE_STATEMENT_H__
#define __EXECUTABLE_STATEMENT_H__

#include "statement.h"

class ExecutableStatement : public Statement
{
	public:
		static const bool trace = 0;

		ExecutableStatement(const string & label);

		virtual ~ExecutableStatement();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;
};

#endif
