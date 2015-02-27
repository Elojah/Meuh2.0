;int	ft_toupper(int c)

global	_ft_toupper

_ft_toupper:
	mov		rax , rdi
	cmp		rdi, 'a'
	jl		.exit
	cmp		rdi, 'z'
	jg		.exit
	sub		rax, 32
	ret
	.exit:
		ret
