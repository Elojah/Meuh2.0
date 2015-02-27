; int	ft_islower(int c)

global	_ft_islower

_ft_islower:

	cmp		rdi, 97
	jb		.nolower
	cmp		rdi, 122
	ja		.nolower
	mov		rax, 1
	ret
	.nolower:
		mov		rax, 0
		ret
