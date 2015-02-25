;int	ft_putchar(int c)

section .data
	char	db 0

section .text

global _ft_putchar

_ft_putchar:
		push rdi
	mov		[rel char], rdi
	lea		rsi, [rel char]
	mov		rdi, 1
	mov		rdx, 1
	mov		rax, 0X2000004
	syscall
		pop rax
	ret
