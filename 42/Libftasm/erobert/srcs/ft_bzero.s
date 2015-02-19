;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/10 16:13:18 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:49:59 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_bzero
	extern		_ft_memset

_ft_bzero:
	start:
		jmp		loop
	loop:
		cmp		rsi,	0
		je		end
		dec		rsi
		mov		[rdi],	byte 0
		inc		rdi
		jmp		loop
	end:
		ret
