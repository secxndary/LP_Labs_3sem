#include <wchar.h>
#include <iostream>
#include <tchar.h>
#include "Error.h"
#include "Parm.h"

namespace Parm 
{
	PARM getparm(int argc, _TCHAR* argv[]) 
	{
		PARM parm;
		wchar_t* in = nullptr;
		wchar_t* out = nullptr;
		wchar_t* log = nullptr;
		if (argc == 1) 
			throw ERROR_THROW(100);

		for (int i = 1; i < argc; i++) 
		{
			if (argc > PARM_MAX_SIZE) 
				throw ERROR_THROW(104);
			if (wcsstr(argv[i], PARM_IN))
			{
				in = wcsstr(argv[i], PARM_IN);
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
			}
			if (wcsstr(argv[i], PARM_OUT))
			{
				out = wcsstr(argv[i], PARM_OUT);
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
			}
			if (wcsstr(argv[i], PARM_LOG))
			{
				log = wcsstr(argv[i], PARM_LOG);
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
			}
		}

		if (in == nullptr)
			throw ERROR_THROW(100);
		if (out == nullptr)
		{
			wcscpy_s(parm.out, in + wcslen(PARM_OUT) - 1);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}
		if (log == nullptr) 
		{
			wcscpy_s(parm.log, in + wcslen(PARM_LOG) - 1);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}
		return parm;
	}
};