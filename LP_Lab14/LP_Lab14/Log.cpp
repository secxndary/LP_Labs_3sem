#include <iostream>
#include <ctime>

#include "Log.h"

namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG log;

		log.stream = new std::ofstream;
		log.stream->open(logfile);
		if (!log.stream->is_open()) { throw ERROR_THROW(112); }
		wcscpy_s(log.logfile, logfile);

		return log;
	}

	void WriteLine(LOG log, const char* c, ...) {
		const char** pc = &c;
		while (*pc != "") {
			*log.stream << *pc;
			pc++;
		}
		*log.stream << std::endl;
	}
	void WriteLine(LOG log, const wchar_t* c, ...) {

		//wcstombs(char *out, const wchar_t *in, size_t size)

		const wchar_t** pc = &c;
		while (*pc != L"") {
			const int SIZE = 10;
			char buff[SIZE];
			size_t tsize = 0;
			wcstombs_s(&tsize, buff, *pc, SIZE);
			*log.stream << buff;
			pc++;
		}
		*log.stream << std::endl;
	}
	void WriteLog(LOG log) {

		char date[100];
		tm local;
		time_t currentTime;
		currentTime = time(NULL);
		localtime_s(&local, &currentTime);
		strftime(date, 100, "%d.%m.%Y %H:%M:%S", &local);
		*log.stream << "--- �������� --- ����: " << date << std::endl;

	}
	void WriteParm(LOG log, Parm::PARM parm) {

		char buff[PARM_MAX_SIZE];
		size_t tsize = 0;

		*log.stream << "--- ��������� --- " << std::endl;
		wcstombs_s(&tsize, buff, parm.in, PARM_MAX_SIZE);
		*log.stream << "-in : " << buff << std::endl;
		wcstombs_s(&tsize, buff, parm.out, PARM_MAX_SIZE);
		*log.stream << "-out: " << buff << std::endl;
		wcstombs_s(&tsize, buff, parm.log, PARM_MAX_SIZE);
		*log.stream << "-log: " << buff << std::endl;
	}
	void WriteIn(LOG log, In::IN in) {

		*log.stream << "--- �������� ������ --- " << std::endl;
		*log.stream << "���������� �������� : " << in.size << std::endl;
		*log.stream << "���������� �����    : " << in.lines << std::endl;
		*log.stream << "���������������     : " << in.ignor << std::endl;
	}
	void WriteError(LOG log, Error::ERROR error) {

		*log.stream << "--- ������!!! --- " << std::endl;
		*log.stream << "������ " << error.id << ":" << error.message << std::endl;

		if (error.inext.line != -1) { *log.stream << "������ " << error.inext.line << std::endl << "�������: " << error.inext.col << std::endl << std::endl; }
	}
	void Close(LOG log) {
		log.stream->close();
		delete log.stream;
	}
}