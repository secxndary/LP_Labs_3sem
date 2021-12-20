﻿#include "stdafx.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "Russian");
	Log::LOG log;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);                            // получить параметры
		log = Log::getstream(parm.log);											// получить поток записи в файл
		Log::writeLog(log);														// написать заголовок протокола
		Log::writeParm(log, parm);												// записать в протокол параметры
		In::IN in = In::getin(parm.in, log.stream);								// считать входной файл
		Log::writeIn(log.stream, in);


		in.words = In::getWordsTable(log.stream, in.text, in.code, in.size);	// разобрать на токены
		Lexer::LEX tables;														// создать таблицу лексем
		bool lex_ok = Lexer::analyze(tables, in, log, parm);					// выполнить лексический анализ
		LT::writeLexTable(log.stream, tables.lextable);							// записать в протокол таблицы лексем и идентификаторов 
		IT::writeIdTable(log.stream, tables.idtable);							// а также соответствие токенов и лексем
		LT::writeLexemsOnLines(log.stream, tables.lextable);					// записать построчно лексемы
		LT::writeLexTable(log.stream, tables.lextable);							// записать в протокол таблицы лексем и идентификаторов 
		IT::writeIdTable(log.stream, tables.idtable);							// а также соответствие токенов и лексем
		LT::writeLexemsOnLines(log.stream, tables.lextable);					// записать построчно лексемы
		if (!lex_ok)										
		{
			Log::writeLine(log.stream, LEXERROR, "");
			Log::writeLine(&std::cout, LEXERROR, STOP, "");						// ошибка лексического анализа
			return 0;
		}
		else
			Log::writeLine(&std::cout, LEXGOOD, "");							// успешная запись в протокол


		MFST_TRACE_START(log.stream);
		MFST::Mfst mfst(tables, GRB::getGreibach());							// выполнить синтаксический анализ
		bool synt_ok = mfst.start(log);
		mfst.savededucation();
		mfst.printrules(log);													// вывести дерево разбора
		if (!synt_ok)									
		{
			Log::writeLine(log.stream, SYNTERROR, "");
			Log::writeLine(&std::cout, SYNTERROR, STOP, "");					// ошибка синтаксического анализа
			return 0;
		}
		else 
			Log::writeLine(&std::cout, SYNTGOOD, "");							// успешная запись в протокол


		bool sem_ok = Semantic::semanticsCheck(tables, log);					// выполнить семантический анализ
		if (!sem_ok)											
		{
			Log::writeLine(log.stream, SEMERROR, "");
			Log::writeLine(&std::cout, SEMERROR, STOP, "");						// ошибка семантического анализа
			return 0;
		}
		else
			Log::writeLine(&std::cout, SEMGOOD, "");							// успешная запись в протокол


		bool polish_ok = Polish::PolishNotation(tables, log);					// выполнить преобразование выражений в польской записи
		if (!polish_ok)										
		{
			Log::writeLine(log.stream, POLISHERROR, "");
			Log::writeLine(&std::cout, POLISHERROR, STOP, "");					// ошибка преобразования выражений
			return 0;
		}
		else Log::writeLine(&std::cout, POLISHGOOD, "");						// успешная запись в протокол


		Log::writeLine(log.stream, MESSAGE, "");
		LT::writeLexTable(log.stream, tables.lextable);							// записать в протокол новые таблицы лексем
		IT::writeIdTable(log.stream, tables.idtable);							// и идентификаторов в польской записи
		LT::writeLexemsOnLines(log.stream, tables.lextable);					// а также соответствие токенов и лексем
		Log::writeLine(&std::cout, MESSAGE, "");								// в протокол и в консось
		IT::writeIdTable(&std::cout, tables.idtable);							// записать в командную строку новые таблицы лексем и идентификаторов 
		LT::writeLexTable(&std::cout, tables.lextable);							// а также соответствие токенов и лексем
		LT::writeLexemsOnLines(&std::cout, tables.lextable);					// в протокол и в консоль


		Gener::CodeGeneration(tables, parm, log);								// выполнить генерацию кода
		Log::writeLine(log.stream, ALLGOOD, "");								// итог работы программы
		Log::writeLine(&std::cout, ALLGOOD, "");								// в протокол и в консоль
		Log::Close(log);													    // закрыть протокол

	}


	catch (Error::ERROR e)
	{
		Log::writeError(log.stream, e);											// обработка исключений
	}
}


