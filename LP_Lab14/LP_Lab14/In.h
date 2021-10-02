#pragma once
#define IN_MAX_LEN_TEXT 1024*1024				
#define IN_CODE_ENDL '\n'						

//#define IN_CODE_TABLE {\
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::T, '|' ,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::SP,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::T,IN::S,IN::S,IN::S,IN::S,IN::S,IN::S,IN::S,IN::T,\
//    IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::L,IN::S,IN::L,IN::S,IN::L,IN::L, \
//    IN::L,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T, \
//    IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::L,IN::L,IN::L,IN::L,IN::L, \
//    IN::L,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T, \
//    IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::S,IN::L,IN::S,IN::L,IN::F, \
//     																						         \
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::L,IN::L,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::L,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, \
//    IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L, \
//    IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L, \
//    IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L, \
//    IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L, \
//}


#define IN_CODE_TABLE {\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::T,  '|',IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::SP,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::T,IN::S,IN::S,IN::S,IN::S,IN::S,IN::S,IN::S,IN::T,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::L,IN::S,IN::L,IN::S,IN::L,IN::L,\
 IN::L,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::L,IN::L,IN::L,IN::L,IN::L,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
 IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::L,IN::S,IN::L,IN::F,\
     																							 \
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::L,IN::L,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::L,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,\
}

namespace In
{
    struct IN
    {
        enum { T, F, I, L, S, SP };     // True, False, Ignore, Literal, Separator, Space
        int size = 0;								
        int lines = 1;			
        int ignor = 0;
        int col = 0;
        unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];
        int code[256] = IN_CODE_TABLE;
    };
    IN getin(wchar_t infile[]);					
};