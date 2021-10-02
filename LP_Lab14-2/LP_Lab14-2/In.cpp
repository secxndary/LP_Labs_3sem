#include "stdafx.h"

namespace In
{
	IN getin(Parm::PARM parm)
	{
		std::ofstream fout;
		fout.open(parm.out);
		std::ifstream file(parm.in);
		if (!file.is_open())
			throw ERROR_THROW(110);
		if (!fout.is_open())
			throw ERROR_THROW(110);

		IN input;
		input.size = input.lines = input.ignor = 0;
		input.text = new unsigned char[IN_MAX_LEN_TEXT];


		int l = IN::T, posstr = 0;

		do
		{
			l = file.get();
			if (l != EOF)
			{
				if (l == IN_CODE_ENDL)
				{
					if (input.size == 0 || input.text[input.size - 1] == '|')
					{
						input.ignor++;
						continue;
					}

					posstr = 0;
					input.lines++;
					input.text[input.size] = IN_CODE_DELIMITER;
					input.size++;

				}
			}
			else {}

			switch (input.code[l])
			{
			case IN::F:
				throw ERROR_THROW_IN(111, input.lines, posstr);
				break;
			case IN::I:
				input.ignor++;
				continue;
				break;
			case IN::T:
				input.text[input.size] = (char)l;
				input.size++;
				break;
			case IN::N:
				if (input.size != 0 && input.code[input.text[input.size - 1]] == IN::S) // 1 усл, чтобы не выйти за границы
				{
					input.text[input.size - 1] = (char)l;
					input.ignor++;
				}
				else
				{
					input.text[input.size] = (char)l;
					input.size++;
				}
				break;
			case IN::S:
				if (input.text[input.size - 1] == ' ' || input.code[input.text[input.size - 1]] == IN::N) // если предыдущий символ -- разделитель
				{
					input.ignor++;
				}
				else
				{
					input.text[input.size] = (char)l;
					input.size++;
				}
				break;

			}

		} while (l != EOF);

		input.text[input.size] = '\0';
		file.close();
		fout.close();
		return input;
	}
}
