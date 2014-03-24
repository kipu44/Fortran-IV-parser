
#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "block.h"

class Program
{
	public:
		static const bool trace = Block::trace;
		static const bool debug = Block::debug;

	public:
		Program(const string & name);

		virtual ~Program();

		virtual string toFortran();

		virtual string toCPlusPlus();

		void addLine(Line * newLine);

	private:
		Block code;
		string name;
};

#endif
