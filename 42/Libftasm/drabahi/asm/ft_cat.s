%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT		1
%define READ		3
%define WRITE		4
; %define FCNTL		92 ;int fcntl(int fildes, int cmd); getfd(1)

section .data
	string:
		.buffer db	0, 0

section .text
	global	_ft_cat

_ft_cat:
	start:
	; 	push	rdi
	; mov		rsi, 1
	; mov		rax, MACH_SYSCALL(FCNTL)
	; syscall
	; 	pop		rdi
	; and		rax, 1
	; cmp		rax, 1
	; je		.erreur
		push	rdi
	; je		.read
	.read:
			pop		rdi
		mov		rdx, 1
		lea		rsi, [rel string.buffer]
		mov		rax, MACH_SYSCALL(READ)
		syscall
		jc		.erreur ; test le dernier bit des flag
		cmp		rax, 0
		jle		.end
			push	rdi
		jmp		.write
	.write:
		mov		rdi, STDOUT
		mov		rdx, 1
		lea		rsi, [rel string.buffer]
		mov		rax, MACH_SYSCALL(WRITE)
		syscall
		cmp		rax, -1
		je		.erreur
		jmp		.read
	.erreur:
		ret
	.end:
		ret
