;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 21:47:52 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:52:20 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_isascii

_ft_isascii:
	start:
		cmp	rdi,	0
		jl	isnot
		cmp	rdi,	127
		jg	isnot
		jmp	isascii
	isnot:
		mov	rax,	0
		ret
	isascii:
		mov	rax,	1
		ret
