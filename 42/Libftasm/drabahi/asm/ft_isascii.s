; int	ft_isascii(int c)

global	_ft_isascii

_ft_isascii:
	mov		rax, 0
	cmp		rdi, 127
	jle		.yes
	ret
	.yes:
		mov		rax, 1
		ret
