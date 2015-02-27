; int	ft_isalpha(int c)

global	_ft_isalpha

_ft_isalpha:

	cmp		rdi, 65
	jl		.noasc
	cmp		rdi, 122
	jg		.noasc
	cmp		rdi, 90
	jle		.asc
	cmp		rdi, 97
	jge		.asc
	.noasc:
		mov		rax,0;
		jmp		.exit
	.asc:
		mov		rax, 1
		jmp		.exit
	.exit:
		ret
