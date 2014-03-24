
// #include "aritmeticStatement.h"
// #include "aritmeticIf.h"
#include "end.h"
#include "format.h"
#include "goTo.h"
#include "comment.h"
#include "program.h"
#include "read.h"
#include "stop.h"
#include "write.h"

#include <fstream>

using namespace std;

void translate(const char * fileName)
{
	static const bool trace = 0;
	static const bool debug = 0;

	fstream file;
	file.open(fileName);

	if(!file)
	{
		cerr << "file cannot be opened: " << fileName << "\n";
		return;
	}

	Program program("main");

	string source = "";

	string line;
	for(getline(file, line); file; getline(file, line))
	{
		source += line + "\n";

		trim(line);

		if(debug) cout << "\nline: " << line << "\n";

		if(trace) cout << "\n1\n";

		if(!line.empty())
		{
			if(trace) cout << "\n2\n";

			if(line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
			{
				if(trace) cout << "\n3\n";

				program.addLine(new Comment(line.substr(2)));

				if(trace) cout << "\n4\n";
			}
			else
			{
				if(trace) cout << "\n5\n";

				toLower(line);

				unsigned p = 0;
				while(isdigit(line[p]))
				{
					p++;
				}

				if(trace) cout << "\n5,5\n";

				string label = "";
				if(p > 0)
				{
					label = line.substr(0, p);
					line.substr(p).swap(line); 
					trim(line);
					if(debug) cout << "label: " << label << "\n";
					if(debug) cout << "rest: " << line << "\n";
				}

				if(trace) cout << "\n6\n";

				if(startsWith(line, "format"))
				{
					if(trace) cout << "\na\n";

					program.addLine(new Format(line.substr(7), label));

					if(trace) cout << "\nb\n";
				}
				else if(startsWith(line, "read"))
				{
					if(trace) cout << "\nc\n";

					program.addLine(new Read(line.substr(5), label));

					if(trace) cout << "\nd\n";
				}
				else if(startsWith(line, "write"))
				{
					if(trace) cout << "\ne\n";

					program.addLine(new Write(line.substr(6), label));

					if(trace) cout << "\nf\n";
				}
				else if(startsWith(line, "stop"))
				{
					if(trace) cout << "\ni\n";

					program.addLine(new Stop(label));

					if(trace) cout << "\nj\n";
				}
				else if(startsWith(line, "end"))
				{
					if(trace) cout << "\nk\n";

					program.addLine(new End(label));

					if(trace) cout << "\nl\n";
				}
				else if(startsWith(line, "go to"))
				{
					if(trace) cout << "\nm\n";

					program.addLine(new GoTo(line.substr(5), label));

					if(trace) cout << "\nn\n";
				}
				// else if(startsWith(line, "if"))
				// {
				// 	if(trace) cout << "\nm\n";

				// 	program.addLine(new AritmeticIf(line.substr(2), label));

				// 	if(trace) cout << "\nn\n";
				// }
				// else
				// {
				// 	if(trace) cout << "\np\n";

				// 	program.addLine(new AritmeticStatement(line, label));

				// 	if(trace) cout << "\nq\n";
				// }

				if(trace) cout << "\n7\n";
			}

			if(trace) cout << "\n8\n";
		}

		if(trace) cout << "\n9\n";
	}

	if(trace) cout << "\n10\n";

	cout << "\n/*\n" << source << "*/\n";

	if(trace) cout << "\n11\n";

	cout << "\n/*\n" << program.toFortran() << "*/\n";

	if(trace) cout << "\n12\n";

	cout << "\n\n" << program.toCPlusPlus() << "\n";

	if(trace) cout << "\n13\n";

	file.close();
}

int main(int argc, char const * argv[])
{
	for(int i = 1; i < argc; ++i)
	{
		cerr << "argv[" << i << "]: " << argv[i] << "\n";
		translate(argv[i]);
	}
	return 0;
}

