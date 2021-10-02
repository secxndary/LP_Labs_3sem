#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm);
		Log::WriteIn(log, in);
		Lex::LEX lex = Lex::lexAnalys(log, in);
		LT::showTable(lex.lextable, parm);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		std::cout << "При компиляции возникла ошибка. Просмотрите файл log";
	}
}
