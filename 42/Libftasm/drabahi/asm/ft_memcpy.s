; void	*ft_memcpy(void *s1, const void *s2, size_t n)

global _ft_memcpy

_ft_memcpy:
	cmp		rdi, 0
	je		.exit
	cmp		rsi, 0
	je		.exit
	cmp		rdx, 0
	je		.exit
	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb
	.exit:
		ret

