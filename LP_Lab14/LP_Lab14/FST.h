#pragma once
#include <iostream>
#include <tchar.h>
#include <vector>
#include <string>
#include <fstream>
#include "Error.h"
#include "In.h"

namespace FST
{
	struct RELATION							
	{
		char symbol;						
		short nnode;						
		RELATION(
			char ñ = 0x00,					
			short ns = NULL);				
	};

	struct NODE								
	{
		short n_relation;					
		RELATION* relations;				
		NODE();
		NODE(short n, RELATION rel, ...);
	};

	struct FST								
	{
		const char* string;					 
		short position = 0;					
		short nstates;						
		NODE* nodes;						
		short* rstates;						
		FST(
			const char* s,					
			short ns,						
			NODE n, ...						
		);
	};

	bool execute(							
		FST& fst							
	);
};