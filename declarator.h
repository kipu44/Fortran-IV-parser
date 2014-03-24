
#ifndef __DECLARATOR_H__
#define __DECLARATOR_H__

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Declarator
{
	private:
		static const bool trace = 0;

	public:
		static Declarator & getInstance();
	
	private:
		Declarator();
		Declarator(const Declarator &);
		Declarator & operator=(const Declarator &);
		~Declarator();
		string declareVariable(const string & type, const string & variable, const bool & semicolon);
		string declareInt(const string & variable, const bool & semicolon);
		string declareFloat(const string & variable, const bool & semicolon);

		set<string> declared;

	public:
		string declare(const string & variable, const bool & semicolon);
};

#endif
