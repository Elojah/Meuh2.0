;char	*ft_strcat(char *s1, const char *s2)

global	_ft_strcat

_ft_strcat:
	mov		rax, rdi
	cmp		rdi, 0
	je		.exit
	cmp		rsi, 0
	je		.exit
	.finrdi:
		cmp		[rdi], byte 0
		je		.cat
		inc		rdi
		jmp		.finrdi
	.cat:
		mov		cl, [rsi]
		mov		[rdi], cl
		inc		rdi
		inc		rsi
		cmp		[rsi], byte 0
		je		.exit
		jmp		.cat
	.exit:
		mov		cl, [rsi]
		mov		[rdi], cl
		ret
