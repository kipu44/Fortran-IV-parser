
#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#include <string>

using namespace std;

class Variable
{
	public:
		Variable(const string & name);

		virtual ~Variable();

		virtual string toCPlusPlus();

		virtual string toFortran();

	protected:
		const string name;
};

#endif
