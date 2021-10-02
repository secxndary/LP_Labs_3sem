
#pragma once
#define LEXEMA_FIXSIZE	1			// ������������� ������ �������
#define LT_MAXSIZE		4096		// ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX	0xfffffff	// ��� �������� ������� ���������������
#define LEX_INTEGER		't'	// ������� ��� integer
#define LEX_STRING		't'	// ������� ��� string
#define LEX_ID			'i'	// ������� ��� ��������������
#define LEX_LITERAL		'l'	// ������� ��� ��������
#define LEX_FUNCTION	'f'	// ������� ��� function
#define LEX_DECLARE		'd'	// ������� ��� declare
#define LEX_RETURN		'r'	// ������� ��� return
#define LEX_PRINT		'p'	// ������� ��� print
#define LEX_MAIN		'm'	// ������� ��� main
#define LEX_SEMICOLON	';'	// ������� ��� ;
#define LEX_COMMA		','	// ������� ��� ,
#define LEX_LEFTBRACE	'{'	// ������� ��� {
#define LEX_BRACELET	'}'	// ������� ��� }
#define LEX_LEFTTHESIS	'('	// ������� ��� (
#define LEX_RIGHTTHESIS	')'	// ������� ��� )
#define LEX_PLUS		'v'	// ������� ��� +
#define LEX_MINUS		'v'	// ������� ��� -
#define LEX_STAR		'v'	// ������� ��� *
#define LEX_DIRSLASH	'v'	// ������� ��� /
#define LEX_OPERATOR	'v'	// ������� ��� ����������
#define LEX_EQUAL		'='


namespace LT		// ������� ������
{
	struct Entry	// ������ ������� ������
	{
		unsigned char lexema;	// �������
		int sn;					// ����� ������ � �������� ������
		int idxTI;				// ������ � ������� ��������������� ��� LT_TI_NULLIDX
	};

	struct LexTable				// ��������� ������� ������
	{
		int maxsize;			// ������� ������� ������ < LT_MAXSIZE
		int size;				// ������� ������ ������� ������ < maxsize
		Entry* table;			// ������ ����� ������� ������
	};

	LexTable Create(		// ������� ������� ������
		int size			// ������� ������� ������ < LT_MAXSIZE
	);

	void Add(				// �������� ������ � ������� ������
		LexTable& lextable,	// ��������� ������� ������
		Entry entry			// ������ ������� ������
	);

	Entry GetEntry(			// �������� ������ ������� ������
		LexTable& lextable,	// ��������� ������� ������
		int n				// ����� ���������� ������
	);

	void Delete(LexTable& lextable);	// ������� ������� ������ (���������� ������)

	Entry writeEntry(					// ��������� ������ ������� ������
		Entry& entry,
		unsigned char lexema,
		int indx,
		int line
	);

	void showTable(LexTable lextable, Parm::PARM parm);	// ����� ������� ������
};