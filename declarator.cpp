
#include "declarator.h"

Declarator & Declarator::getInstance()
{
	static Declarator instance;

	return instance;
}
//----------------------------------------------------------------
Declarator::Declarator()
{
}
//----------------------------------------------------------------
Declarator::~Declarator()
{
}
//----------------------------------------------------------------
string Declarator::declareVariable(const string & type, const string & variable, const bool & semicolon)
{
	if(trace) cout << "\nDeclarator::declareVariable{\n";

	string result = "";

	if(declared.count(variable) == 0)
	{
		declared.insert(variable);
		result = type + " " + variable + (semicolon ? "": ";\n");
	}

	if(trace) cout << "\n}Declarator::declareVariable\n" << "result: " << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Declarator::declareInt(const string & variable, const bool & semicolon)
{
	if(trace) cout << "\nDeclarator::declareInt{\n";

	string result = declareVariable("int", variable, semicolon);

	if(trace) cout << "\n}Declarator::declareInt\n" << "result: " << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Declarator::declareFloat(const string & variable, const bool & semicolon)
{
	if(trace) cout << "\nDeclarator::declareFloat{\n";

	string result = declareVariable("float", variable, semicolon);

	if(trace) cout << "\n}Declarator::declareFloat\n" << "result: " << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Declarator::declare(const string & variable, const bool & semicolon)
{
	if(trace) cout << "\nDeclarator::declare{\n";

	string result = (this->*('i' <= variable[0] && variable[0] <= 'n' ? &Declarator::declareInt : &Declarator::declareFloat))(variable, semicolon);

	// string result = declareVariable('i' <= variable[0] && variable[0] <= 'n' ? "int" : "float", variable, semicolon);

	if(trace) cout << "\n}Declarator::declare\n" << "result: " << result << "\n";

	return result;
}
//----------------------------------------------------------------
