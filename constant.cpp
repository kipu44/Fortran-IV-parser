
#include "constant.h"

Constant::Constant(const string & name)
 : name(name)
{
}
//----------------------------------------------------------------
Constant::~Constant()
{
}
//----------------------------------------------------------------
string Constant::toCPlusPlus()
{
	return name;
}
//----------------------------------------------------------------
string Constant::toFortran()
{
	return name;
}
//----------------------------------------------------------------
