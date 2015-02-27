; int	ft_isdigit(int c)
global	_ft_isdigit
_ft_isdigit:
	mov		rax, 0
	cmp		rdi, 48
	jl		.exit
	cmp		rdi, 57
	jg		.exit
	mov		rax, 1
	.exit:
		ret
