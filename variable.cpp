
#include "variable.h"

Variable::Variable(const string & name)
 : name(name)
{
}
//----------------------------------------------------------------
Variable::~Variable()
{
}
//----------------------------------------------------------------
string Variable::toCPlusPlus()
{
	return name;
}
//----------------------------------------------------------------
string Variable::toFortran()
{
	return name;
}
//----------------------------------------------------------------
