#pragma once
#include "stdafx.h"
#define max_word 1000
#define size_word 20


namespace Lex
{
	struct LEX
	{
		IT::IdTable idtable;;
		LT::LexTable lextable;
	};

	bool checkBrace(unsigned char** word, int k);
	unsigned char** divideText(unsigned char text[], int size);
	LEX lexAnalys(Log::LOG log, In::IN in);
}