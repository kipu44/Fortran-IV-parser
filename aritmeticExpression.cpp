
#include "aritmeticExpression.h"

AritmeticExpression::AritmeticExpression(const string & text)
 : text(text)
{
	if(trace) cout << "\nAritmeticExpression::AritmeticExpression{\n";

	if(trace) cout << "\n}AritmeticExpression::AritmeticExpression\n";
}
//----------------------------------------------------------------
AritmeticExpression::~AritmeticExpression()
{
}
//----------------------------------------------------------------
string AritmeticExpression::toCPlusPlus()
{
	return text;
}
//----------------------------------------------------------------
string AritmeticExpression::toFortran()
{
	return text;
}
//----------------------------------------------------------------
