.586  
.model flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD

includelib LP_asm01a.lib
getmin PROTO :DWORD, :DWORD
getmax PROTO :DWORD, :DWORD
int_to_char PROTO :DWORD, :SDWORD

includelib ucrt.lib
SetConsoleOutputCP PROTO :DWORD
SetConsoleCP PROTO :DWORD
SetConsoleTitleA PROTO: DWORD
GetStdHandle PROTO :DWORD
WriteConsoleA PROTO :DWORD,  :DWORD,  :DWORD,  :DWORD,  :DWORD

printconsole PROTO :DWORD, :DWORD


.stack 4096

.const
endl equ 0ah				;символ перевода строки
str_endl byte endl,0

.data
consoleTitle byte "Console Title", 0
arr		dword 12, 5, 100, 1, 2, 3, 12, 14, 9, 7  ; массив из 10 элементов размером 4 байта
value   dword ?
text   byte "getmax - getmin = "
result byte 40 dup(0)
	   byte 10

.code


main PROC
	
	push 10
	push  offset arr
	call getmax
	mov value, eax

	push 10
	push  offset arr
	call getmin
	sub value, eax

	push value
	push offset result
	call int_to_char

	push 1251d
	call SetConsoleCP
	push 1251d
	call SetConsoleCP
	invoke printconsole, offset text, offset consoleTitle
	invoke printconsole, offset str_endl, offset consoleTitle

	push -1
	call ExitProcess
main ENDP

;----------------------------------

printconsole proc uses eax ebx ecx edi esi,
				  pstr :dword,
				  ptitle :dword
		
		push ptitle
		call SetConsoleTitleA
		push -11
		call GetStdHandle
		mov esi,pstr
		mov edi, -1

count:
		inc edi
		cmp byte ptr [esi + edi], 0
		jne count

		push 0
		push 0
		push edi
		push pstr
		push eax
		call WriteConsoleA

		ret
printconsole endp
;----------------------------------

end main