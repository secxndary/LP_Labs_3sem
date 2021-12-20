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
		LTRL1 sdword 1
		LTRL2 byte 'Len + 1: ', 0
		LTRL3 byte 'concat: ', 0
		LTRL4 byte 'test1', 0
		LTRL5 byte 'num B:', 0
		LTRL6 sdword 10
		LTRL7 sdword 3
		LTRL8 byte 'Just ', 0
		LTRL9 byte 'string', 0
		LTRL10 byte '70', 0
		LTRL11 byte 'from string in number: ', 0
		LTRL12 sdword 2
		LTRL13 byte 'Left shift: ', 0
		LTRL14 sdword 52
		LTRL15 byte ' ', 0
		LTRL16 byte ' after cycle ', 0
		LTRL17 byte 'new 0x', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		minres sdword 0
		standk sdword 0
		standstr dword ?
		mainzz sdword 0
		maind sdword 0
		mainx sdword 0
		mainy sdword 0
		mainm sdword 0
		mainn sdword 0
		mainstrx dword ?
		mainstry dword ?
		mainstrz dword ?
		maine sdword 0
		mainresult sdword 0
		maint sdword 0
		mainab sdword 0
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


;------------- stand --------------
stand PROC,
	standa : dword, standb : dword  
; -------- save registers -------
push ebx
push edx
; -------------------------------

push standa
push offset buffer
call lenght
push eax
push LTRL1
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
mov standk, ebx


push offset LTRL2
call outstr


push standk
call outnum

push offset newline
call outstr


push standb
push standa
push offset buffer
call concat
mov standstr, eax

push offset LTRL3
call outstr


push standstr
call outstr

push offset newline
call outstr

; ------ restore registers ------
pop edx
pop ebx
; -------------------------------
ret
stand ENDP
;--------------------------------


;------------- MAIN --------------
main PROC

push offset LTRL4
call outstr

push offset newline
call outstr


pop ebx
mov mainzz, ebx


pop ebx
mov maind, ebx


push offset LTRL5
call outstr

push offset newline
call outstr


push mainzz
call outnum

push offset newline
call outstr

push LTRL6

pop ebx
mov mainx, ebx

push LTRL7

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


push mainx
call outnum

push offset newline
call outstr

push LTRL6

pop ebx
mov mainm, ebx

push LTRL7

pop ebx
mov mainn, ebx

push mainm
push mainn
pop ebx
pop eax
cdq
idiv ebx
push eax

pop ebx
mov mainm, ebx


push mainm
call outnum

push offset newline
call outstr

mov mainstrx, offset LTRL8
mov mainstry, offset LTRL9
mov mainstrz, offset LTRL10

push offset LTRL11
call outstr


push mainstrz
push offset buffer
call atoii
push eax

pop ebx
mov maine, ebx


push maine
call outnum

push offset newline
call outstr

push mainx
push LTRL1
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax
push LTRL12
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
mov mainresult, ebx


push offset LTRL13
call outstr


push mainresult
call outnum

push offset newline
call outstr


push mainy
push mainx
call min
push eax

pop ebx
mov maint, ebx


push maint
call outnum

push offset newline
call outstr

push LTRL7

pop ebx
mov mainab, ebx

mov edx, mainab
cmp edx, LTRL14

jnz cycle2
jmp cyclenext2
cycle2:

push mainab
call outnum


push offset LTRL15
call outstr

push mainab
push LTRL12
pop ebx
pop eax
add eax, ebx
push eax
push LTRL12
pop ebx
pop eax
imul eax, ebx
push eax

pop ebx
mov mainab, ebx

mov edx, mainab
cmp edx, LTRL14

jnz cycle2
cyclenext2:

push offset LTRL16
call outstr


push mainab
call outnum

push offset newline
call outstr


push offset LTRL17
call outstr

push offset newline
call outstr


push maind
call outnum

push offset newline
call outstr


push mainstry
push mainstrx
call stand

push 0
call ExitProcess
main ENDP
end main
