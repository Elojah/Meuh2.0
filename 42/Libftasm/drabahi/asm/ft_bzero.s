; void	ft_bzero(void *s, size_t n)

global	_ft_bzero

_ft_bzero:
	.check:
		cmp		rsi, 0
		je		.exit
		mov		[rdi], byte 0
		dec		rsi
		inc		rdi
		jmp		.check
	.exit:
		ret
