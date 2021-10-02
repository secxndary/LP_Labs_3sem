#include <iostream>
#include <ctime>
#include "Out.h"

namespace Out
{
	OUT getout(wchar_t outfile[]) 
	{
		OUT out;
		out.stream = new std::ofstream;
		out.stream->open(outfile);
		if (!out.stream->is_open())		
			throw ERROR_THROW(112);
		wcscpy_s(out.outfile, outfile);
		return out;
	}

	void WriteLineOut (OUT out, const char* c, ...) 
	{
		const char** pc = &c;
		while (*pc != "")
		{
			*out.stream << *pc;
			pc++;
		}
		*out.stream << std::endl;
	}

	void CloseOut (OUT out)
	{
		out.stream->close();
		delete out.stream;
	}
}