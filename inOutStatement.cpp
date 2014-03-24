
#include "inOutStatement.h"

InOutStatement::InOutStatement(const string & label)
 : ExecutableStatement(label)
{
	if(trace) cout << "\nInOutStatement::InOutStatement{\n";

	if(trace) cout << "\n}InOutStatement::InOutStatement\n";
}
//----------------------------------------------------------------
InOutStatement::~InOutStatement()
{
}
//----------------------------------------------------------------
