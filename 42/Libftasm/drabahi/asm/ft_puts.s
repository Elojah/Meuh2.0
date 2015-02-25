;int	ft_puts(const char *s)

section .data
null	db "(null)"
rc		db 10

section .text


global	_ft_puts
extern	_ft_strlen

_ft_puts:
		push		rdi
	cmp			rdi, 0
	je			.null
	call		_ft_strlen
		pop			rdi
	mov			rdx, rax
	mov			rsi, rdi
	mov			rdi, 1
	mov			rax, 0X2000004
	syscall
	cmp			rax, -1
	je			.erreur
	jmp			.finish
	.null:
			pop		rdi
		lea		rsi, [rel null]
		mov		rdx, 6
		mov		rax, 0X2000004
		syscall
		cmp		rax, -1
		je		.erreur
	.finish:
		lea		rsi, [rel rc]
		mov		rdi, 1
		mov		rdx, 1
		mov		rax, 0X2000004
		syscall
		cmp		rax, -1
		je		.erreur
		mov		rax, 10
		ret

	.erreur:
		ret
