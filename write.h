
#ifndef __WRITE_H__
#define __WRITE_H__

#include "outStatement.h"

#include <iostream>

using namespace std;

class Write : public OutStatement
{
	private:
		static const bool trace = OutStatement::trace;

	private:
		string commasToArrows(const string & text);

	public:
		Write(const string & text, const string & label);

		virtual ~Write();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	private:
		string bracket;
		string variables;
};

#endif
