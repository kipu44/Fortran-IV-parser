
#include "goTo.h"

GoTo::GoTo(const string & target, const string & label)
 : ExecutableStatement(label),
   target(new Label(target))
{
}
//----------------------------------------------------------------
GoTo::~GoTo()
{
	delete target;
}
//----------------------------------------------------------------
string GoTo::toCPlusPlus(const int & indent)
{
	return string(indent, '\t') + "goto " + target->toCPlusPlus(false) + ";\n";
}
//----------------------------------------------------------------
string GoTo::toFortran(const int & indent)
{
	return label->toFortran() + string(indent, '\t') + "go to " + target->toFortran() + ";\n";
}
//----------------------------------------------------------------
