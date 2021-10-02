#include "stdafx.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;
		wchar_t* in = nullptr, * out = nullptr, * log = nullptr;
		int f = 0;

		if (argc < 1) // если не передаются аргументы в main
			throw ERROR_THROW(100);
		for (int i = 1; i < argc; i++) // 1 - т.к. имя файла на 0
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE) // проверка длины строки каждого входного параметра
				throw ERROR_THROW(104);
			//wcsstr - Возвращает указатель на первое вхождение строки поиска в строке
			if (wcsstr(argv[i], PARM_IN)) // проверка на наличие -in
				f = 1;
		}

		if (f == 0)
			throw ERROR_THROW(100);

		for (int i = 1; i < argc; i++)
		{
			in = wcsstr(argv[i], PARM_IN);
			if (in)
			{
				wcscpy_s(parm.in, in + wcslen(PARM_IN)); // +wcslen(PARM_IN) для сдвига на длину строки PARM_IN, чтобы не было повтора 
				break;
			}
		}

		for (int i = 1; i < argc; i++)
		{
			out = wcsstr(argv[i], PARM_OUT);
			if (out)
			{
				wcscpy_s(parm.out, out + wcslen(PARM_OUT));
				break;
			}
		}

		if (!out) // если не задано значение out
		{
			wcscpy_s(parm.out, in + wcslen(PARM_IN));
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}

		for (int i = 1; i < argc; i++)
		{
			log = wcsstr(argv[i], PARM_LOG);
			if (log)
			{
				wcscpy_s(parm.log, log + wcslen(PARM_LOG));
				break;
			}
		}

		if (!log) // если не задано значение log
		{
			wcscpy_s(parm.log, in + wcslen(PARM_IN));
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
}