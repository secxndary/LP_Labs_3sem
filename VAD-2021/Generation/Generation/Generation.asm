.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib "../Debug/GenLib.lib
ExitProcess PROTO:DWORD 
.stack 4096


 outnum PROTO : DWORD

 outstr PROTO : DWORD

 concat PROTO : DWORD, : DWORD, : DWORD

 lenght PROTO : DWORD, : DWORD

 atoii  PROTO : DWORD,  : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 byte 'test 2', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
.code

;----------- MAIN ------------
main PROC

push offset LTRL1
call outstr

push 0
call ExitProcess
main ENDP
end main
