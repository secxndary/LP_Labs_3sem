.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib "../Debug/GenLib.lib
ExitProcess PROTO:DWORD 
.stack 4096


 outnum PROTO : DWORD

 outstr PROTO : DWORD

 strcopy PROTO : DWORD, : DWORD

 lenght PROTO : DWORD, : DWORD

 atoii  PROTO : DWORD,  : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 sdword 5
		LTRL2 byte 'Lenght + 5:          ', 0
		LTRL3 byte 'String copy:         ', 0
		LTRL4 sdword 10
		LTRL5 sdword 3
		LTRL6 byte '10 module 3:         ', 0
		LTRL7 byte 'VAD-2021', 0
		LTRL8 byte 'Course Project Test', 0
		LTRL9 byte '70', 0
		LTRL10 byte 'Cycle:               ', 0
		LTRL11 sdword 125
		LTRL12 sdword 1
		LTRL13 byte '; ', 0
		LTRL14 byte 'Number after cycle:  ', 0
		LTRL15 sdword 21
		LTRL16 sdword 13
		LTRL17 byte 'Minimal number:      ', 0
		LTRL18 byte 'Number from string:  ', 0
		LTRL19 sdword 2
		LTRL20 sdword 6
		LTRL21 byte 'Left shift 2 on 6:   ', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		minres sdword 0
		stringsk sdword 0
		stringsstr dword ?
		mainx sdword 0
		mainy sdword 0
		mainstrx dword ?
		mainstry dword ?
		mainstrz dword ?
		mainab sdword 0
		mainminone sdword 0
		mainmintwo sdword 0
		mainresmin sdword 0
		mainsnum sdword 0
		mainshiftnum sdword 0
		mainshiftres sdword 0
.code

;------------- min --------------
min PROC,
	minx : sdword, miny : sdword  
; -------- save registers -------
push ebx
push edx
; -------------------------------
mov edx, minx
cmp edx, miny

jl right1
jg wrong1
right1:
push minx

pop ebx
mov minres, ebx

jmp next1
wrong1:
push miny

pop ebx
mov minres, ebx

next1:
; ------ restore registers ------
pop edx
pop ebx
; -------------------------------
mov eax, minres
ret
min ENDP
;--------------------------------


;------------- strings --------------
strings PROC,
	stringsa : dword, stringsb : dword  
; -------- save registers -------
push ebx
push edx
; -------------------------------

push stringsa
push offset buffer
call lenght
push eax
push LTRL1
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov stringsk, ebx


push offset LTRL2
call outstr


push stringsk
call outnum

push offset newline
call outstr


push stringsb
push offset buffer
call strcopy
mov stringsstr, eax

push offset LTRL3
call outstr


push stringsstr
call outstr

push offset newline
call outstr

; ------ restore registers ------
pop edx
pop ebx
; -------------------------------
ret
strings ENDP
;--------------------------------


;------------- MAIN --------------
main PROC
push LTRL4

pop ebx
mov mainx, ebx

push LTRL5

pop ebx
mov mainy, ebx

push mainx
push mainy
pop ebx 
mov edx, 0 
pop eax 
idiv ebx 
push edx 
mov eax, edx

pop ebx
mov mainx, ebx


push offset LTRL6
call outstr


push mainx
call outnum

push offset newline
call outstr

mov mainstrx, offset LTRL7
mov mainstry, offset LTRL8
mov mainstrz, offset LTRL9

push mainstry
push mainstrx
call strings


push offset LTRL10
call outstr

push LTRL11

pop ebx
mov mainab, ebx

mov edx, mainab
cmp edx, LTRL12

jg cycle2
jmp cyclenext2
cycle2:

push mainab
call outnum


push offset LTRL13
call outstr

push mainab
push LTRL5
pop ebx
pop eax
cdq
idiv ebx
push eax

pop ebx
mov mainab, ebx

mov edx, mainab
cmp edx, LTRL12

jg cycle2
cyclenext2:
push offset newline
call outstr


push offset LTRL14
call outstr


push mainab
call outnum

push offset newline
call outstr

push LTRL15

pop ebx
mov mainminone, ebx

push LTRL16

pop ebx
mov mainmintwo, ebx


push mainmintwo
push mainminone
call min
push eax

pop ebx
mov mainresmin, ebx


push offset LTRL17
call outstr


push mainresmin
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL18
call outstr


push mainstrz
push offset buffer
call atoii
push eax

pop ebx
mov mainsnum, ebx


push mainsnum
call outnum

push offset newline
call outstr

push LTRL19

pop ebx
mov mainshiftnum, ebx

push mainx
push LTRL20
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
mov mainshiftres, ebx


push offset LTRL21
call outstr


push mainshiftres
call outnum

push offset newline
call outstr

push 0
call ExitProcess
main ENDP
end main
