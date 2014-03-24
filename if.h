
#ifndef __IF_H__
#define __IF_H__

#include "nonexecutableStatement.h"
#include "executableStatement.h"

class If : public NonexecutableStatement
{
	public:
		If(const string & label);

		virtual ~If();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;

	protected:
		ExecutableStatement * statement;
};

#endif
