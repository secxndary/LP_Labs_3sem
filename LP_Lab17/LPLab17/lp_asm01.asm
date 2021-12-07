.586  
.model flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD

.stack 4096

.const

.data

arr dword 12, 5, 100, 1, 2, 3, 12, 14, 9, 7  ; массив из 10 элементов размером 4 байта

.code

getmin PROC  near  uses  ebx ecx edi esi,
			array: dword, len: dword
		
		mov esi, array
		mov eax, [esi]
		mov ecx, len

	CYCLE:
		mov ebx, [esi]
		cmp ebx, eax

		jns c0

			mov eax, [ esi]
		c0:
			add esi, 4

		loop CYCLE


		ret
getmin ENDP


main PROC


	push 10
	push offset arr
	call getmin


	push -1
	call ExitProcess
main ENDP



end main

