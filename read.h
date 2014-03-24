
#ifndef __READ_H__
#define __READ_H__

#include "declarator.h"
#include "inStatement.h"

#include <iostream>
#include <list>

using namespace std;

class Read : public InStatement
{
	private:
		static const bool trace = 0;

	public:
		Read(const string & t, const string & label);

		virtual ~Read();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	private:
		string bracket;
		string variablesStr;
		list<string> variables;

		void splitToVariables(const string & text);
		string commasToArrows();
		string declareVariables(const int & indent);

};

#endif
