
#ifndef __ARITMETIC_STATEMENT_H__
#define __ARITMETIC_STATEMENT_H__

#include "utils.h"

#include "declarator.h"
#include "float.h"
#include "int.h"
#include "executableStatement.h"

class AritmeticStatement : public ExecutableStatement
{
	private:
		static const bool trace = ExecutableStatement::trace;

	public:
		AritmeticStatement(const string & text, const string & label);

		virtual ~AritmeticStatement();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	protected:
		Variable * variable;
		// AritmeticExpression * expression;
		string expression;
};

#endif
