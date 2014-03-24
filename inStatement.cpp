
#include "inStatement.h"

InStatement::InStatement(const string & label)
 : InOutStatement(label)
{
	if(trace) cout << "\nInStatement::InStatement{\n";

	if(trace) cout << "\n}InStatement::InStatement\n";
}
//----------------------------------------------------------------
InStatement::~InStatement()
{
}
//----------------------------------------------------------------
