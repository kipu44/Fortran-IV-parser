
#ifndef __STATEMENT_H__
#define __STATEMENT_H__

#include "label.h"
#include "line.h"

class Statement : public Line
{
	private:
		static const bool trace = 0;

	public:
		Statement(const string & label);

		virtual ~Statement();

		virtual string toCPlusPlus(const int & indent) = 0;

		virtual string toFortran(const int & indent) = 0;

	protected:
		Label * label;
};

#endif
