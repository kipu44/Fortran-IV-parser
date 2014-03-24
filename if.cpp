
#include "if.h"

If::If(const string & label)
 : NonexecutableStatement(label),
   statement(NULL)
{
}
//----------------------------------------------------------------
If::~If()
{
	delete statement;
}
//----------------------------------------------------------------
