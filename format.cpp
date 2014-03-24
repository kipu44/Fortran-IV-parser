
#include "format.h"

Format::Format(const string & t, const string & label)
 : InOutStatement(label)
{
	if(trace) cout << "\nFormat::nFormat{\n";

	if(trace) cout << "t.size(): " << t.size() << "\n";

	int lastClosingBracket = t.find_last_of(")");
	if(trace) cout << "lastClosingBracket: " << lastClosingBracket << "\n";

	bracket = t.substr(1, lastClosingBracket - 1);
	variables = lastClosingBracket == t.size() - 1 ? string("") : t.substr(lastClosingBracket + 2);

	if(trace) cout << "  bracket|" << bracket << "|\n";
	if(trace) cout << "variables|" << variables << "|\n";

	if(trace) cout << "\n}Format::nFormat\n";
}
//----------------------------------------------------------------
Format::~Format()
{
}
//----------------------------------------------------------------
string Format::toCPlusPlus(const int & indent)
{
	return "";
}
//----------------------------------------------------------------
string Format::toFortran(const int & indent)
{
	if(trace) cout << "\nFormat::toFortran{\n";

	string result = label->toFortran() + string(indent, '\t') + "format (" + bracket + ") " + variables + "\n";

	if(trace) cout << "\n}Format::toFortran\n" << result << "\n";

	return result;
}
//----------------------------------------------------------------
