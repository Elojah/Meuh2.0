;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/18 19:02:54 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 13:03:50 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_strdup
	extern		_ft_strlen
	extern		_malloc
	extern		_ft_memcpy

_ft_strdup:
	start:
		push	rdi
		call	_ft_strlen
		push	rax
		mov		rdi,		rax
		inc		rdi
		call	_malloc
		cmp		rax,		0
		je		error
		pop		rdx
		pop		rsi
		mov		rdi,		rax
		call	_ft_memcpy
		ret
	error:
		pop		rdx
		pop		rsi
		mov		rax,		0
		ret
