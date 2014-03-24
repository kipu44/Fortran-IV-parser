
#include "end.h"

End::End(const string & label)
 : NonexecutableStatement(label)
{
}
//----------------------------------------------------------------
End::~End()
{
}
//----------------------------------------------------------------
string End::toCPlusPlus(const int & indent)
{
	return string(indent, '\t') + "// end\n";
}
//----------------------------------------------------------------
string End::toFortran(const int & indent)
{
	return label->toFortran() + string(indent, '\t') + "end\n";
}
//----------------------------------------------------------------
