#include "stdafx.h"

namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE) throw ERROR_THROW(105);
		LexTable Table;
		Table.maxsize = size;
		Table.size = 0;
		Table.table = new Entry[size];
		return Table;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size > lextable.maxsize) throw ERROR_THROW(106);
		lextable.table[lextable.size++] = entry;
	}

	Entry GetEntry(LexTable& lextable, int n)
	{
		return lextable.table[n];
	}

	void Delete(LexTable& lextable)
	{
		delete[] lextable.table;
	}

	Entry writeEntry(Entry& entry, unsigned char lexema, int indx, int line)
	{
		entry.lexema = lexema;
		entry.idxTI = indx;
		entry.sn = line;
		return entry;
	}

	void showTable(LexTable lextable, Parm::PARM parm)		// вывод таблицы лексем
	{
		std::fstream fout;
		fout.open(parm.out, std::ios::app);//ios::app - дописыввать в конец файла
		if (!fout.is_open())
			throw ERROR_THROW(110);
		fout << "01 ";

		int number = 1;
		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].sn != number && lextable.table[i].sn != -1)   //нумерация строк
			{
				while (lextable.table[i].sn - number > 1)	// пока не дойдём до последней строки
					number++;
				if (number < 9)
					fout << std::endl << '0' << lextable.table[i].sn << ' ';
				else
					fout << std::endl << lextable.table[i].sn << ' ';
				number++;
			}
			fout << lextable.table[i].lexema;
			if (lextable.table[i].lexema == LEX_ID || lextable.table[i].lexema == LEX_OPERATOR || lextable.table[i].lexema == LEX_LITERAL)
				fout << "<" << lextable.table[i].idxTI << ">";
		}
	}
}