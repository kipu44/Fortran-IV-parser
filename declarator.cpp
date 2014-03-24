
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

	if(trace) cout << "\nDeclarator::declareVariable 1\n";

	if(declared.count(variable) == 0)
	{
		if(trace) cout << "\nDeclarator::declareVariable 2\n";

		declared.insert(variable);

		if(trace) cout << "\nDeclarator::declareVariable 3\n";

		result = "";

		if(trace) cout << "\nDeclarator::declareVariable 4\n" << "result: " << result << "\ntype: " << type << "\n";

		result += type;

		if(trace) cout << "\nDeclarator::declareVariable 5\n" << "result: " << result << "\n";

		result += " ";

		if(trace) cout << "\nDeclarator::declareVariable 6\n" << "result: " << result << "\nvariable: " << variable << "\n";
	}
	
	result += variable;

	if(trace) cout << "\nDeclarator::declareVariable 7\n" << "result: " << result << "\nsemicolon: " << semicolon << "\n";

	result += (semicolon ? "": ";\n");

	if(trace) cout << "\nDeclarator::declareVariable 8\n" << "result: " << result << "\n";

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
