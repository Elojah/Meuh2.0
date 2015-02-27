; int	ft_isupper(int c)

global	_ft_isupper

_ft_isupper:

	cmp		rdi, 65
	jb		.noupper
	cmp		rdi, 90
	ja		.noupper
	mov		rax, 1
	ret
	.noupper:
		mov		rax,0;
		ret
