
#include "statement.h"

Statement::Statement(const string & label)
 : label(new Label(label))
{
	if(trace) cout << "\nStatement::Statement{\n";

	if(trace) cout << "\n}Statement::Statement\n";
}
//----------------------------------------------------------------
Statement::~Statement()
{
	delete label;
}
//----------------------------------------------------------------
