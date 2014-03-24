
#include "write.h"

Write::Write(const string & text, const string & label)
 : OutStatement(label)
{
	if(trace) cout << "\nWrite::Write{\n";

	size_t lastClosingBracket = text.find_last_of(")");

	if(trace) cout << "\nWrite::Write 1\n" << "lastClosingBracket: " << lastClosingBracket << "\n";

	bracket = text.substr(1, lastClosingBracket - 1);

	if(trace) cout << "\nWrite::Write 2\n" << "bracket: " << bracket << "\n";

	variables = text.substr(lastClosingBracket + 1);

	if(trace) cout << "\nWrite::Write 3\n" << "variables: " << variables << "\n";

	if(trace) cout << "\n}Write::Write\n";
}
//----------------------------------------------------------------
Write::~Write()
{
}
//----------------------------------------------------------------
string Write::commasToArrows(const string & text)
{
	if(trace) cout << "\nWrite::commasToArrows{\n";

	string result = "";

	string fragment;

	unsigned comma = -1;
	for(unsigned i = 0; i < text.size(); ++i)
	{
		if(text[i] == ',')
		{
			//p i
			// r, a, c

			fragment = text.substr(comma + 1, i - comma - 1);
			trim(fragment);

			if(trace) cout << "\nWrite::commasToArrows 1\n" << "\nfragment:" << fragment << "\n";

			result += " << \" \" << " + fragment;

			if(trace) cout << "\nWrite::commasToArrows 2\n" << "\nresult:" << result << "\n";

			comma = i;
		}
	}

	fragment = text.substr(comma + 1);
	trim(fragment);

	if(trace) cout << "\nWrite::commasToArrows 3\n" << "\nfragment:" << fragment << "\n";

	result += " << \" \" << " + fragment;

	if(trace) cout << "\n}Write::commasToArrows\n" << "\nresult:" << result << "\n";

	return result;
}
//----------------------------------------------------------------
string Write::toCPlusPlus(const int & indent)
{
	return label->toCPlusPlus(true)
		 + string(indent, '\t')
		 + "cout" + commasToArrows(variables) + " << \"\\n\";\n";
}
//----------------------------------------------------------------
string Write::toFortran(const int & indent)
{
	return label->toFortran()
		 + string(indent, '\t')
		 + "write (" + bracket + ") " + variables + "\n";
}
//----------------------------------------------------------------
