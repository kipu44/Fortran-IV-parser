
#include "stop.h"

Stop::Stop(const string & label)
 : NonexecutableStatement(label)
{
}
//----------------------------------------------------------------
Stop::~Stop()
{
}
//----------------------------------------------------------------
string Stop::toCPlusPlus(const int & indent)
{
	return label->toCPlusPlus(true) + string(indent, '\t') + string("return 0;\n");
}
//----------------------------------------------------------------
string Stop::toFortran(const int & indent)
{
	return label->toFortran() + string(indent, '\t') + string("stop\n");
}
//----------------------------------------------------------------
