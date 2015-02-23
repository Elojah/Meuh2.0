;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/12 14:14:14 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 18:13:01 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .data
	string:
		.char db	10
		.null db	"(null)", 10
		
section .text
	global			_ft_puts
	extern			_ft_putstr

_ft_puts:
	start:
		cmp			rdi,			0
		je			error
		call		_ft_putstr
		jmp			end
	error:
		mov			rdi,			STDOUT
		lea			rsi,			[rel string.null]
		mov			rdx,			7
		mov			rax,			MACH_SYSCALL(WRITE)
		syscall
		ret
	end:
		mov			rdi,			STDOUT
		lea			rsi,			[rel string.char]
		mov			rdx,			1
		mov			rax,			MACH_SYSCALL(WRITE)
		syscall
		ret
