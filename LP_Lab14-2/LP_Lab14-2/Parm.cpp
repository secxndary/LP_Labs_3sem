#include "stdafx.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;
		wchar_t* in = nullptr, * out = nullptr, * log = nullptr;
		int f = 0;

		if (argc < 1) // ���� �� ���������� ��������� � main
			throw ERROR_THROW(100);
		for (int i = 1; i < argc; i++) // 1 - �.�. ��� ����� �� 0
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE) // �������� ����� ������ ������� �������� ���������
				throw ERROR_THROW(104);
			//wcsstr - ���������� ��������� �� ������ ��������� ������ ������ � ������
			if (wcsstr(argv[i], PARM_IN)) // �������� �� ������� -in
				f = 1;
		}

		if (f == 0)
			throw ERROR_THROW(100);

		for (int i = 1; i < argc; i++)
		{
			in = wcsstr(argv[i], PARM_IN);
			if (in)
			{
				wcscpy_s(parm.in, in + wcslen(PARM_IN)); // +wcslen(PARM_IN) ��� ������ �� ����� ������ PARM_IN, ����� �� ���� ������� 
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

		if (!out) // ���� �� ������ �������� out
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

		if (!log) // ���� �� ������ �������� log
		{
			wcscpy_s(parm.log, in + wcslen(PARM_IN));
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
}