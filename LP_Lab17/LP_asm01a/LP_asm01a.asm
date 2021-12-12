.586  
.model flat, stdcall
.code
getmin PROC  uses  ebx ecx edi esi, array: dword, len: dword
		
		mov esi, array
		mov eax, [esi]
		mov ecx, len

	CYCLE:
		mov ebx, [esi]
		cmp ebx, eax

		js c0
		jns c1

		c1:
			mov eax, [esi]
		c0:
			add esi, 4

		loop CYCLE


		ret
getmin ENDP

getmax PROC  uses  ebx ecx edi esi, array: dword, len: dword
		
		mov esi, array
		mov eax, [esi]
		mov ecx, len

	CYCLE:
		mov ebx, [esi]
		cmp ebx, eax

		js c1
		jns c0

		c1:
			mov eax, [esi]
		c0:
			add esi, 4

		loop CYCLE


		ret
getmax ENDP

int_to_char PROC uses eax ebx ecx edi esi,
			pstr: dword,
			intfield: sdword

	mov edi, pstr
	mov esi, 0
	mov eax, intfield
	cdq                          ;знак числа распространяется с eax на edx
	mov ebx, 10
	idiv ebx
	test eax, 80000000h
	jz plus						 ;если положительное число то переходим по метке	
	neg eax
	neg edx
	mov cl, '-'
	mov [edi], cl
	inc edi
plus:
	push dx
	inc esi
	test eax, eax                ;eax == ?
	jz fin
	cdq
	idiv ebx					 ;eax = eax/ebx, остаток в edx
	jmp plus
fin:
	mov ecx, esi
write:
	pop bx
	add bl, '0'
	mov[edi], bl
	inc edi
	loop write
	ret
int_to_char ENDP

end