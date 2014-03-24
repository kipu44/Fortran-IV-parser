
#include "block.h"

Block::Block()
{
}
//----------------------------------------------------------------
Block::~Block()
{
	for(list<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		delete *it;
	}
}
//----------------------------------------------------------------
string Block::toFortran(const int & indent)
{
	if(trace) cout << "\nBlock::toFortran{\n";

	string result = "";

	if(trace) cout << "\nBlock::toFortran 1\n";

	for(list<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		if(trace) cout << "\nBlock::toFortran 2\n";

		result += (*it)->toFortran(indent);

		if(trace) cout << "\nBlock::toFortran 3\n";
	}

	if(trace) cout << "\n}Block::toFortran\n";

	return result;
}
//----------------------------------------------------------------
string Block::toCPlusPlus(const int & indent)
{
	if(trace) cout << "\nBlock::toCPlusPlus{\n";

	string result = "";

	if(trace) cout << "\nBlock::toCPlusPlus 1\n";
	
	for(list<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		if(trace) cout << "\nBlock::toCPlusPlus 2\n";

		result += (*it)->toCPlusPlus(indent);

		if(trace) cout << "\nBlock::toCPlusPlus 3\n" << "result:\n" << result << "\n";
	}

	if(trace) cout << "\n}Block::toCPlusPlus\n";

	return result;
}
//----------------------------------------------------------------
void Block::addLine(Line * newLine)
{
	lines.push_back(newLine);
	
	if(debug) cout << "\t" << lines.back()->toCPlusPlus(2) << "\n";
	if(debug) cout << "\t" << lines.back()->toFortran(2) << "\n";
}
//----------------------------------------------------------------
