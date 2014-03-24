
#ifndef __COMMENT_H__
#define __COMMENT_H__

#include "line.h"

#include <iostream>

using namespace std;

class Comment : public Line
{
	private:
		static const bool trace = Line::trace;

	public:
		Comment(const string & text);

		virtual ~Comment();

		virtual string toCPlusPlus(const int & indent);

		virtual string toFortran(const int & indent);

	private:
		const string text;
};

#endif
