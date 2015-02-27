; char	*ft_strdup(const char *s1)

global	_ft_strdup
extern	_ft_strlen
extern	_malloc
extern	_ft_memcpy

_ft_strdup:
	cmp			rdi, 0
	je			.error
		push		rdi
	call		_ft_strlen
	inc			rax
		push		rax
	mov			rdi, rax
	call		_malloc
	cmp			rax, 0
	je			.error
		pop			rdx
		pop			rsi
	mov			rdi, rax
	call		_ft_memcpy
	ret
	.error:
			pop		rdx
			pop		rsi
		mov		rax, 0
		ret


