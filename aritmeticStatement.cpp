
#include "aritmeticStatement.h"

AritmeticStatement::AritmeticStatement(const string & text, const string & label)
 : ExecutableStatement(label)
{
	if(trace) cout << "\nAritmeticStatement::AritmeticStatement{\n";

	if(trace) cout << "\nAritmeticStatement::AritmeticStatement 1\n" << "text: " << text << "\n";

	size_t equal = text.find('=');

	if(trace) cout << "\nAritmeticStatement::AritmeticStatement 2\n" << "equal: " << equal << "\n";

	string x = text.substr(0, equal - 1);
	trim(x);

	if(trace) cout << "\nAritmeticStatement::AritmeticStatement 3\n" << "x: " << x << "\n";

	if('i' <= x[0] && x[0] <= 'n')
	{
		variable = new Int(x);
	}
	else
	{
		variable = new Float(x);
	}

	expression = text.substr(equal + 1);
	trim(expression);

	if(trace) cout << "\nAritmeticStatement::AritmeticStatement 4\n" << "expression: " << expression << "\n";

	if(trace) cout << "\n}AritmeticStatement::AritmeticStatement\n";
}
//----------------------------------------------------------------
AritmeticStatement::~AritmeticStatement()
{
	delete variable;
	// delete expression;
}
//----------------------------------------------------------------
string AritmeticStatement::toCPlusPlus(const int & indent)
{
	if(trace) cout << "\nAritmeticStatement::toCPlusPlus{\n";

	string result = label->toCPlusPlus(true);

	if(trace) cout << "\nAritmeticStatement::toCPlusPlus 1\n" << "result: " << result << "\n";

	result += string(indent, '\t');

	if(trace) cout << "\nAritmeticStatement::toCPlusPlus 2\n" << "result: " << result << "\n";

	result += Declarator::getInstance().declare(variable->toCPlusPlus(), true);

	if(trace) cout << "\nAritmeticStatement::toCPlusPlus 3\n" << "result: " << result << "\n";

	result += " = ";

	if(trace) cout << "\nAritmeticStatement::toCPlusPlus 4\n" << "result: " << result << "\n";

	result += parse(expression);

	if(trace) cout << "\nAritmeticStatement::toCPlusPlus 5\n" << "result: " << result << "\n";

	result += ";\n";

	if(trace) cout << "\n}AritmeticStatement::toCPlusPlus\n" << "result: " << result << "\n";

	return result;
}
//----------------------------------------------------------------
string AritmeticStatement::toFortran(const int & indent)
{
	return label->toFortran()
		 + string(indent, '\t')
		 + variable->toFortran() + " = " + expression + "\n";
}
//----------------------------------------------------------------
