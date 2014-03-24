
#ifndef __FORMAT_H__
#define __FORMAT_H__

#include "inOutStatement.h"

#include <iostream>

using namespace std;

class Format : public InOutStatement
{
	private:
		static const bool trace = 0;

	public:
		Format(const string & t, const string & label);

		virtual ~Format();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	private:
		string bracket;
		string variables;
};

#endif
