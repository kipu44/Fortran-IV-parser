
#include "outStatement.h"

OutStatement::OutStatement(const string & label)
 : InOutStatement(label)
{
	if(trace) cout << "\nOutStatement::OutStatement{\n";

	if(trace) cout << "\n}OutStatement::OutStatement\n";
}
//----------------------------------------------------------------
OutStatement::~OutStatement()
{
}
//----------------------------------------------------------------
