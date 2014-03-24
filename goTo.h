
#ifndef __GO_TO_H__
#define __GO_TO_H__

#include "label.h"
#include "executableStatement.h"

class GoTo : public ExecutableStatement
{
	public:
		GoTo(const string & target, const string & label);

		virtual ~GoTo();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	protected:
		Label * target;
};

#endif
