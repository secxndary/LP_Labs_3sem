#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"

namespace Out
{
	struct OUT
	{ 
		wchar_t outfile[PARM_MAX_SIZE]; 
		std::ofstream* stream; 
	};

	static const OUT INITOUT = { L"", NULL };
	OUT getout(wchar_t outfile[]);			
	void WriteLineOut (OUT out, const char* c, ...);
	void CloseOut (OUT log);					
};