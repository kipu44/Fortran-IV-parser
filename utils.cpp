
#include "utils.h"

void trim(string & text)
{
	static const bool trace = 0;

	static const string white = " \t";

	if(trace) cout << "\ntrim{\n" << "text: " << text << "\n";

	size_t begin = text.find_first_not_of(white);

	if(trace) cout << "\ntrim 1\n" << "begin: " << begin << "\n";

	if(begin != string::npos)
	{
		size_t end = text.find_last_not_of(white);
	
		if(trace) cout << "\ntrim 2\n" << "end: " << end << "\n";
	
		text.substr(begin, end - begin + 1).swap(text);
	}

	if(trace) cout << "\n}trim\n";
}
//----------------------------------------------------------------
void toLower(string & text)
{
	for(unsigned i = 0; i < text.size(); ++i)
	{
		text[i] = tolower(text[i]);
	}
}
//----------------------------------------------------------------
bool startsWith(const string & text, const string & begin)
{
	static const bool trace = false;

	if(trace) cout << "\nA\n";

	if(text.size() < begin.size())
	{
		return false;
	}

	if(trace) cout << "\nB\n";

	for(unsigned i = 0; i < begin.size(); ++i)
	{
		if(trace) cout << "\nC\n";

		if(trace) cout << char(text[i]);
		if(trace) cout << char(begin[i]);
		if(trace) cout << char(tolower(text[i]));
		if(trace) cout << char(tolower(begin[i]));

		if(tolower(text[i]) != tolower(begin[i]))
		{
			return false;
		}

		if(trace) cout << "\nD\n";
	}

	if(trace) cout << "\nE\n";

	return true;
}
//----------------------------------------------------------------
size_t opening(const string & text, const int & endiec)
{
	int zamkniete = 0;
	size_t pozycja = endiec;
	while(pozycja >= 0)
	{
		switch(text[pozycja])
		{
			case '(':
				zamkniete--;
				if(zamkniete == 0)
				{
					return pozycja;
				}
				break;
			case ')':
				zamkniete++;
				break;
		}
		pozycja--;
	}
	return string::npos;
}
//----------------------------------------------------------------
string lewyArgument(const string & text)
{
	if(text.empty())
	{
		return "";
	}

	if(text[text.size() - 1] == ')')
	{
		size_t pozycja = opening(text, text.size() - 1);
		return text.substr(pozycja);
	}
	else
	{
		size_t pozycja = text.find_last_of("*/+-()");
		return text.substr(pozycja + 1);
	}
}
//----------------------------------------------------------------
size_t closure(const string & text, const int & begin)
{
	int otwarte = 0;
	size_t pozycja = begin;
	while(pozycja < text.size())
	{
		switch(text[pozycja])
		{
			case '(':
				otwarte++;
				break;
			case ')':
				otwarte--;
				if(otwarte == 0)
				{
					return pozycja;
				}
				break;
		}
		pozycja++;
	}
	return string::npos;
}
//----------------------------------------------------------------
string prawyArgument(const string & text)
{
	if(text.empty())
	{
		return "";
	}

	if(text[0] == '(')
	{
		size_t pozycja = closure(text, 0);
		return text.substr(0, pozycja);
	}
	else
	{
		size_t pozycja = text.find_first_of("*/+-()");
		return text.substr(0, pozycja - 1);
	}
}
//----------------------------------------------------------------
string parsuj(string text)
{
	static const bool trace = 0;

	for(unsigned i = 0; i < text.size(); ++i)
	{
		if(trace) cout << "text[" << i << "]: " << text[i] << "\n";
		if(text[i] == '*' && i + 1 < text.size() && text[i + 1] == '*')
		{
			string lewo = text.substr(0, i - 1);
			string prawo = text.substr(i + 2);

			if(trace) cout << " na lewo: " << lewo << "\n";
			if(trace) cout << " ^ " << "\n";
			if(trace) cout << "na prawo: " << prawo << "\n";

			string lewy = lewyArgument(lewo);
			string prawy = prawyArgument(prawo);

			if(trace) cout << "lewy: " << lewy << "\n";
			if(trace) cout << "prawy: " << prawy << "\n";

			string potega = "pow(" + lewy + ", " + prawy + ")";

			if(trace) cout << potega << "\n";

			string resztaL = text.substr(0, i - lewy.size() - 1);
			string resztaP = text.substr(i + 2 + prawy.size());

			if(trace) cout << "resztaL: " << resztaL << "\n";
			if(trace) cout << "resztaP: " << resztaP << "\n";

			if(trace) cout << resztaL << potega << resztaP << "\n";

			text = resztaL + potega + resztaP;

			i = resztaL.size() + potega.size();
		}
	}

	return text;
}
//----------------------------------------------------------------
