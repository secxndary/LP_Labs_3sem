#include "stdafx.h"
\

namespace IT
{
	IdTable Create(int size)
	{
		if (size > TI_MAXSIZE)
			throw ERROR_THROW(108);
		IdTable Table;
		Table.maxsize = size;
		Table.size = 0;
		Table.table = new Entry[size];
		return Table;
	}

	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size > idtable.maxsize) throw ERROR_THROW(109);
		idtable.table[idtable.size++] = entry;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, unsigned char id[ID_MAXSIZE])
	{
		for (int i = 0; i < idtable.size; i++)
		{
			if (_mbscmp(idtable.table[i].id, id) == 0)
				return i;
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete[] idtable.table;
	}
}