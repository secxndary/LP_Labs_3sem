#include <iostream>
#include <fstream>
#include <algorithm>
#include <io.h>
#include "In.h"
#include "Error.h"

namespace In
{
	IN getin(wchar_t nameFile[])
	{
		bool flagSpace = false;
		bool flagSeparator = false;
		bool flagLiteral = false;
		int position = 0;
		int positionL = 0;
		unsigned short positionErr = 1;
		std::fstream fin(nameFile, std::ios_base::in);

		if (fin.fail())
			throw ERROR_THROW(110)
		IN* ptr = new IN;
		ptr->text = new unsigned char[IN_MAX_LEN_TEXT];

		if (!ptr)
			throw ERROR_THROW(1);
		if (!ptr->text)
			throw ERROR_THROW(1);

		for (unsigned char symbol; symbol = fin.get(); positionErr++)
		{
			if (fin.eof())
				break;
			if (symbol == IN_CODE_ENDL)
			{
				ptr->lines++;
				positionErr = 0;
			}

			switch (ptr->code[symbol])
			{
			case IN::T:
			{
				if (flagSpace)
				{
					ptr->text[position++] = ' ';
					ptr->size++;
					flagSpace = false;
				}
				ptr->text[position++] = symbol;
				ptr->size++;
				flagSeparator = false;

				if (symbol == '\'')
				{
					if (flagLiteral)
						flagLiteral = false;
					else
						flagLiteral = true;
				}
				positionL = 0;
				break;
			}
			case IN::F:
			{
				throw ERROR_THROW_IN(111, ptr->lines, positionErr);
			}
			case IN::I:
			{
				ptr->ignor++;
				ptr->size++;
				positionL = 0;

				break;
			}
			case IN::L:
			{
				//if (flagLiteral)
				//{
				//	ptr->text[position++] = symbol;
				//	ptr->size++;
				//}
				//if (ptr->code[symbol - 1] == IN::L)
				//		positionT++;
				//if (positionT > 5)
				//	throw ERROR_THROW_IN(113, ptr->lines, positionErr);
				//if (!flagLiteral)
				//	throw ERROR_THROW_IN(111, ptr->lines, positionErr);

				if (positionL < 5)
				{
					ptr->text[position++] = symbol;
					ptr->size++;
					if (ptr->code[symbol] == IN::L)
						positionL++;
				}
				else
					throw ERROR_THROW_IN(113, ptr->lines, positionErr);
				break;
			}
			case IN::S:
			{
				ptr->text[position++] = symbol;
				ptr->size++;
				flagSeparator = true;
				flagSpace = false;
				positionL = 0;
				break;
			}
			case IN::SP:
			{
				if (!flagSpace && !flagSeparator)
				{
					flagSpace = true;
				}
				if (flagLiteral)
				{
					ptr->text[position++] = ' ';
					ptr->size++;
				}
				positionL = 0;
				break;
			}
			default:
			{
				ptr->text[position] = ptr->code[symbol];
				position++;
				break;
			}

			}
		}

		ptr->text[position] = '\0';
		fin.close();
		return *ptr;
	}
}

//
//#include <iostream>
//#include <fstream>
//#include <algorithm>  
//#include <io.h>
//
//#include "In.h"
//#include "Error.h"
//
//namespace In
//{
//	IN getin(wchar_t nameFile[])
//	{
//		bool space = false;
//		bool separ = false;
//		bool literal = false;
//		int positionArr = 0;
//		unsigned short positionErr = 1;
//		short positionL = 0;
//		short positionT = 0;
//		std::fstream fin(nameFile, std::ios_base::in);
//
//		if (fin.fail())
//			throw ERROR_THROW(110)
//
//			IN* ptr = new IN;
//		ptr->text = new unsigned char[IN_MAX_LEN_TEXT];
//
//		if (!ptr)
//			throw ERROR_THROW(1);
//
//		if (!ptr->text)
//			throw ERROR_THROW(1);
//
//		for (unsigned char symbol; symbol = fin.get(); positionErr++)
//		{
//			if (fin.eof())
//				break;
//
//			if (symbol == IN_CODE_ENDL)
//			{
//				ptr->lines++;
//				positionErr = 0;
//			}
//
//			switch (ptr->code[symbol])
//			{
//			case IN::F:
//			{
//				throw ERROR_THROW_IN(111, ptr->lines, positionErr);
//			}
//			case IN::I:
//			{
//				ptr->ignor++;
//				ptr->size++;
//				ptr->sizes = 0;
//				positionL = 0;
//				break;
//			}
//			case IN::T:
//			{
//				if (space) {
//					ptr->text[positionArr++] = ' ';
//					ptr->size++;
//					space = false;
//				}
//				ptr->text[positionArr++] = symbol;
//				ptr->size++;
//				separ = false;
//
//				if (symbol == '\'')
//				{
//					if (literal) {
//						literal = false;
//					}
//					else {
//						literal = true;
//					}
//				}
//				ptr->sizes = 0;
//				positionL = 0;
//
//				break;
//			}
//			case IN::SP: //проверяет на наличие лишних пробелов
//			{
//				if (!space && !separ) {
//					space = true;
//				}
//
//				if (literal) {
//					ptr->text[positionArr++] = ' '; //после литералов по заданию нужны пробелы
//					ptr->size++;
//				}
//				ptr->sizes = 0;
//				positionL = 0;
//
//				break;
//			}
//			case IN::S:
//			{	ptr->text[positionArr++] = symbol; //берем по-символьно текст 
//			ptr->size++;
//			separ = true;
//			space = false;
//			ptr->sizes = 0;
//			positionL = 0;
//
//			break;
//
//			}
//			case IN::L://тут низя пробелы
//			{
//
//				/*if (ptr->sizes < 6) {
//					ptr->text[positionArr++] = symbol;
//					ptr->size++;
//					ptr->sizes++;
//				}
//				else
//					throw ERROR_THROW_IN(113, ptr->lines, positionErr);*/
//
//
//				if (positionL < 5)
//				{
//					ptr->text[positionArr++] = symbol;
//					ptr->size++;
//					if (ptr->code[symbol] == IN::L)
//						positionL++;
//				}
//				else 
//					throw ERROR_THROW_IN(113, ptr->lines, positionErr);
//
//
//
//				/*if (literal)
//				{
//					ptr->text[positionArr++] = symbol;
//					ptr->size++;
//				}
//				if (!literal)
//					throw ERROR_THROW_IN(111, ptr->lines, positionErr);*/
//
//				/*if (ptr->code[symbol - 1] == IN::L)
//						positionL++;
//				if (positionL > 5)
//				throw ERROR_THROW_IN(113, ptr->lines, positionErr);
//				*/
//
//
//				break;
//			}
//			break;
//			default:
//			{
//				ptr->text[positionArr] = ptr->code[symbol];
//				positionArr++;
//				break;
//			}
//
//			}
//		}
//
//		ptr->text[positionArr] = '\0';
//		fin.close();
//
//		return *ptr;
//	}
//}