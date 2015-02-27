;int	ft_tolower(int c)

global	_ft_tolower

_ft_tolower:
	mov		rax , rdi
	cmp		rdi, 65
	jl		.exit
	cmp		rdi, 90
	jg		.exit
	add		rax, 32
	ret
	.exit:
		ret
