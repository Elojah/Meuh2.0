; void	*ft_memset(void *b, int c, size_t len)

global	_ft_memset

_ft_memset:
	mov		rax, rsi
	mov		rsi, rdi
	mov		rcx, rdx
	rep		stosb
	mov		rax, rsi
	ret
