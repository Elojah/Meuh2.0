;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 21:27:06 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:50:25 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_isalnum
	extern		_ft_isalpha
	extern		_ft_isdigit

_ft_isalnum:
	start:
		call	_ft_isalpha
		cmp		rax,		0
		je		isdigit
		jmp		isalnum
	isdigit:
		call	_ft_isdigit
		cmp		rax,		0
		je		isnot
		jmp		isalnum
	isnot:
		mov		rax,		0
		ret
	isalnum:
		mov		rax,		rdi
		ret
