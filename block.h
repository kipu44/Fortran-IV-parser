
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "line.h"

#include <iostream>
#include <list>

using namespace std;

class Block
{
	private:
		static const bool trace = Line::trace;
		static const bool debug = Line::debug;

	public:
		Block();

		virtual ~Block();

		virtual string toFortran(const int & indent);

		virtual string toCPlusPlus(const int & indent);

		void addLine(Line * newLine);

	private:
		list<Line *> lines;
};

#endif
