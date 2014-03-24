
#include "comment.h"

Comment::Comment(const string & text)
 : text(text)
{
	if(trace) cout << "\nComment::Comment{\n";

	if(trace) cout << "\n}Comment::Comment\n";
}
//----------------------------------------------------------------
Comment::~Comment()
{
}
//----------------------------------------------------------------
string Comment::toCPlusPlus(const int & indent)
{
	if(trace) cout << "\nComment::toCPlusPlus{\n";

	string result = string(indent, '\t') + "// " + text + "\n";

	if(trace) cout << "\n}Comment::toCPlusPlus\n";

	return result;
}
//----------------------------------------------------------------
string Comment::toFortran(const int & indent)
{
	if(trace) cout << "\nComment::toFortran{\n";

	string result = "C\t";

	if(trace) cout << "\nComment::toFortran 1\n" << result << "\n";

	result += text;

	if(trace) cout << "\nComment::toFortran 2\n" << result << "\n";

	result += "\n";

	if(trace) cout << "\n}Comment::toFortran\n" << result << "\n";

	return result;
}
//----------------------------------------------------------------
