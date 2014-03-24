
#include "executableStatement.h"

ExecutableStatement::ExecutableStatement(const string & label)
 : Statement(label)
{
	if(trace) cout << "\nExecutableStatement::ExecutableStatement{\n";

	if(trace) cout << "\n}ExecutableStatement::ExecutableStatement\n";
}
//----------------------------------------------------------------
ExecutableStatement::~ExecutableStatement()
{
}
//----------------------------------------------------------------
