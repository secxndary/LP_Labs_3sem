#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"

namespace Log
{
	LOG getlog(wchar_t logfile[]) //�������� � �������� ���������� ������
	{
		LOG f;
		f.stream = new std::ofstream;
		f.stream->open(logfile);
		if (!f.stream->is_open())
			throw ERROR_THROW(112);
		wcscpy_s(f.logfile, logfile);
		return f;
	}

	void WriteLine(LOG log, char* c, ...) // ������������� �������� ������ � ������� � ��������
	{
		va_list arg;
		va_start(arg, c);
		char* sym = c;
		std::string str;
		while (sym != "")
		{
			str += sym;
			sym = va_arg(arg, char*);
		}
		va_end(arg);
		*log.stream << str << "\n";
		return;
	}

	void WriteLine(LOG log, const wchar_t* c, ...) {
		char convertedBuffer[255];
		const wchar_t** args = &c;

		for (int i = 0; args[i] != L""; ++i) {
			wcstombs_s(nullptr, convertedBuffer, args[i], sizeof(convertedBuffer));
			*log.stream << convertedBuffer;
		}
		*log.stream << std::endl;
	}

	void WriteLog(LOG log) // ������� ��������� ���������
	{
		tm DateNow;
		time_t TimeNow = time(0);
		localtime_s(&DateNow, &TimeNow);
		*log.stream << "----- �������� ----- ����: ";
		//tm_mday - ���� ������, tm_mon - ����� ������(������ � 0, ������� +1), .tm_year - ����� ����, ������� � 1900
		*log.stream << DateNow.tm_mday << "." << DateNow.tm_mon + 1 << "." << 1900 + DateNow.tm_year; // � ����������
		*log.stream << " " << std::setw(2) << DateNow.tm_hour;
		*log.stream << ":" << std::setw(2) << DateNow.tm_min;
		*log.stream << ":" << std::setw(2) << DateNow.tm_sec;
		*log.stream << " ------\n";
		return;
	}

	void WriteParm(LOG log, Parm::PARM parm) //������� ���������� � ������� ���������� � ��������
	{
		char str[255];
		*log.stream << "----- ��������� -----\n";
		//wcstombs -- ����������� ������������������ ������� �������� � ��������������� ������������������ ������������� ��������.
		wcstombs(str, parm.in, wcslen(parm.in)); // ����, ���, ����������
		str[wcslen(parm.in)] = '\0';
		*log.stream << "-in: ";
		log.stream->write(str, strlen(str)) << '\n';

		wcstombs(str, parm.out, wcslen(parm.out)); // ����, ���, ����������
		str[wcslen(parm.out)] = '\0';
		*log.stream << "-out: ";
		log.stream->write(str, strlen(str)) << '\n';

		wcstombs(str, parm.log, wcslen(parm.log)); // ����, ���, ����������
		str[wcslen(parm.log)] = '\0';
		str[wcslen(parm.log) + 1] = '\n';
		*log.stream << "-log: ";
		log.stream->write(str, strlen(str));
		return;
	}

	void WriteIn(LOG log, In::IN in) // ����� ���������� � ������� ������
	{
		*log.stream << std::endl << "----- �������� ������ -----";
		*log.stream << "\n����� ��������:      " << in.size;
		*log.stream << "\n����������������:    " << in.ignor;
		*log.stream << "\n����� �����:         " << in.lines;
		return;
	}

	void WriteError(LOG log, Error::ERROR err) // ����� ������
	{
		if (log.stream->is_open())
		{
			*log.stream << "\n������ " << err.id << ": " << err.message << ", ������ " << err.inext.line << ", ������� " << err.inext.col << "\n\n";
		}
		else
			std::cout << "������ " << err.id << ": " << err.message << ", ������ " << err.inext.line << ", ������� " << err.inext.col << "\n\n";
	}

	void Close(LOG& log) // �������� �������� ������
	{
		if (!log.stream)
			return;
		log.stream->close();
		delete log.stream;
		log.stream = nullptr;
	}
}