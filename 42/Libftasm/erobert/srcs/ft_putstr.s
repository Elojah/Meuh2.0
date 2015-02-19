;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/17 13:35:41 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:53:28 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACH_SYSCALL(nb)		0x2000000 | nb
%define STDOUT					1
%define WRITE					4

section .text
	global			_ft_putstr
	extern			_ft_strlen

_ft_putstr:
	start:
		push		rdi
		call		_ft_strlen
		mov			rdx,			rax
		lea			rsi,			[rel rdi]
		mov			rdi,			STDOUT
		mov			rax,			MACH_SYSCALL(WRITE)
		syscall
		pop			rdi
		ret
