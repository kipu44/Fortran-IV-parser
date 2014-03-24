
#ifndef __OUT_STATEMENT_H__
#define __OUT_STATEMENT_H__

#include "inOutStatement.h"

class OutStatement : public InOutStatement
{
	public:
		static const bool trace = InOutStatement::trace;

		OutStatement(const string & label);

		virtual ~OutStatement();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;
};

#endif
