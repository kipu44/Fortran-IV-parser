
#ifndef __LABEL_H__
#define __LABEL_H__

#include "utils.h"

class Label
{
	private:
		static const bool trace = 0;

	public:
		Label(const string & label);

		virtual ~Label();

		virtual string toCPlusPlus(const bool & front);

		virtual string toFortran();

	private:
		string number;
};

#endif
