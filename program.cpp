
#include "program.h"

Program::Program(const string & name)
 : name(name)
{
}
//----------------------------------------------------------------
Program::~Program()
{
}
//----------------------------------------------------------------
string Program::toFortran()
{
	return "C Fortran IV program:\n" + code.toFortran(1);
}
//----------------------------------------------------------------
string Program::toCPlusPlus()
{
	return "// C++ program:\n"
		 + string("\n")
		 + string("#include <iostream>\n")
		 + string("#include <cmath>\n")
		 + string("\n")
		 + string("using namespace std;\n")
		 + string("\n")
		 + string("int main(int argc, char const * argv[])\n")
		 + string("{\n")
		 + code.toCPlusPlus(1)
		 + string("}\n");
}
//----------------------------------------------------------------
void Program::addLine(Line * newLine)
{
	if(trace) cout << "\naddLine{\n";

	code.addLine(newLine);

	if(trace) cout << "\n}addLine\n";
}
//----------------------------------------------------------------