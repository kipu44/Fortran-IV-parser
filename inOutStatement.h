
#ifndef __IN_OUT_STATEMENT_H__
#define __IN_OUT_STATEMENT_H__

#include "executableStatement.h"

class InOutStatement : public ExecutableStatement
{
	public:
		static const bool trace = ExecutableStatement::trace;

	public:
		InOutStatement(const string & label);

		virtual ~InOutStatement();

		virtual string toCPlusPlus(const int & label) = 0;

		virtual string toFortran(const int & label) = 0;
};

#endif
