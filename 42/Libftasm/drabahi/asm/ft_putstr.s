;int	ft_putstr(const char *s)

section .data
null	db "(null)"

section .text


global	_ft_putstr
extern	_ft_strlen

_ft_putstr:
	push	rdi
	cmp		rdi, 0
	je		.null
	call	_ft_strlen
	pop		rdi
	mov		rdx, rax
	mov		rsi, rdi
	mov		rdi, 1
	mov		rax, 0X2000004
	syscall
	cmp		rax, -1
	je		.erreur
	jmp		.finish
	.null:
		pop	rdi
		lea	rsi, [rel null]
		mov	rdx, 6
		mov	rax, 0X2000004
		syscall
		cmp		rax, -1
		je		.erreur
	.finish:
		mov		rax, 10
		ret
	.erreur:
		ret
