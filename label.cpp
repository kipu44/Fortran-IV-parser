
#include "label.h"

Label::Label(const string & label)
 : number(label)
{
	if(trace) cout << "\nLabel::Label{\n";

	trim(number);

	if(trace) cout << "\n}Label::Label\n";
}
//----------------------------------------------------------------
Label::~Label()
{
}
//----------------------------------------------------------------
string Label::toCPlusPlus(const bool & front)
{
	if(number.empty())
	{
		return number;
	}
	else
	{
		if(front)
		{
			return "_" + number + ":\n";
		}
		else
		{
			return "_" + number;
		}
	}
	// return front && !number.empty() ? string("_") + number + ":\n" : number;
}
//----------------------------------------------------------------
string Label::toFortran()
{
	return "\t" + number;
}
//----------------------------------------------------------------
