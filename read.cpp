
#include "read.h"

Read::Read(const string & t, const string & label)
 : InStatement(label)
{
	if(trace) cout << "\nRead::Read{\n";

	int lastClosingBracket = t.find_last_of(")");
	if(trace) cout << "lastClosingBracket:" << lastClosingBracket << "|\n";

	bracket = t.substr(1, lastClosingBracket - 1);
	if(trace) cout << " bracket|" << bracket << "|\n";

	variablesStr = t.substr(lastClosingBracket + 2);
	splitToVariables(variablesStr);

	if(trace) cout << "\n}Read::Read\n";
}
//----------------------------------------------------------------
Read::~Read()
{
}
//----------------------------------------------------------------
void Read::splitToVariables(const string & text)
{
	if(trace) cout << "\nRead::splitToVariables{\n";

	string result = "";

	string fragment;

	unsigned comma = -1;
	for(unsigned i = 0; i < text.size(); ++i)
	{
		if(text[i] == ',')
		{
			fragment = text.substr(comma + 1, i - comma - 1);
			trim(fragment);

			if(trace) cout << "\nRead::splitToVariables 0\n" << "fragment:" << fragment << "\n";

			variables.push_back(fragment);

			if(trace) cout << "\nRead::splitToVariables 1\n";

			comma = i;
		}
	}

	fragment = text.substr(comma + 1);
	trim(fragment);

	if(trace) cout << "\nRead::splitToVariables 2\n" << "fragment:" << fragment << "\n";

	variables.push_back(fragment);

	if(trace) cout << "\n}Read::splitToVariables\n";
}
//----------------------------------------------------------------
string Read::commasToArrows()
{
	if(trace) cout << "\nRead::commasToArrows{\n";

	string result = "";

	for(list<string>::iterator it = variables.begin(); it != variables.end(); ++it)
	{
		result += " >> ";
		result += *it;
	}

	if(trace) cout << "\n}Read::commasToArrows\n" << "result:" << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Read::declareVariables(const int & indent)
{
	if(trace) cout << "\nRead::commasToArrows{\n";

	string result = "";

	for(list<string>::iterator it = variables.begin(); it != variables.end(); ++it)
	{
		result += string(indent, '\t') + Declarator::getInstance().declare(*it, false);
	}

	if(trace) cout << "\n}Read::commasToArrows\n" << "result:" << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Read::toCPlusPlus(const int & indent)
{
	return declareVariables(indent)
		 + label->toCPlusPlus(true)
		 + string(indent, '\t')
		 + "cin" + commasToArrows() + ";\n";
}
//----------------------------------------------------------------
string Read::toFortran(const int & indent)
{
	return label->toFortran()
		 + string(indent, '\t')
		 + "read (" + bracket + string(") ") + variablesStr + "\n";
}
//----------------------------------------------------------------
