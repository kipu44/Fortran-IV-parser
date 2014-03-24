
#ifndef __IN_STATEMENT_H__
#define __IN_STATEMENT_H__

#include "inOutStatement.h"

class InStatement : public InOutStatement
{
	private:
		static const bool trace = 0;

	public:
		InStatement(const string & label);

		virtual ~InStatement();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;
};

#endif
