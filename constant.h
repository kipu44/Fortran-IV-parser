
#ifndef __CONSTANT_H__
#define __CONSTANT_H__

#include <string>

using namespace std;

class Constant
{
	public:
		Constant(const string & name);

		virtual ~Constant();

		virtual string toCPlusPlus();

		virtual string toFortran();

	protected:
		const string name;
};

#endif
