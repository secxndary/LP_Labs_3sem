#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		out = Out::getout(parm.out);
		Log::WriteLine(log, "Тест:", " без ошибок ", "");
		Log::WriteParm(log, parm);
		Log::WriteLog(log);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		*out.stream << in.text;
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\n\t\tОбработанный исходный код выведен в файл по адресу " << parm.out << ".\n";
		Out::CloseOut(out);
		Log::Close(log);
	}

	catch (Error::ERROR e) 
	{
		std::cout << "Ошибка: " << e.id << ": " << e.message << std::endl << std::endl;
		std::cout << "Строка: " << e.inext.line << " Позиция: " << e.inext.col << std::endl << std::endl;
		Log::WriteError(log, e);
		Log::Close(log);
	};
}