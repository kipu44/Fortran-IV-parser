
#include "aritmeticIf.h"

AritmeticIf::AritmeticIf(const string & text, const string & label)
 : If(label),
   expression(new AritmeticExpression(text))
{
}
//----------------------------------------------------------------
AritmeticIf::~AritmeticIf()
{
	delete expression;
}
//----------------------------------------------------------------
string AritmeticIf::toCPlusPlus(const int & indent)
{
	return string(indent, '\t') + "if" + expression->toCPlusPlus() + "\n";
}
//----------------------------------------------------------------
string AritmeticIf::toFortran(const int & indent)
{
	return string(indent, '\t') + "if" + expression->toFortran() + "\n";
}
//----------------------------------------------------------------
