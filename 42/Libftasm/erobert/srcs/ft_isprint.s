;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 21:54:38 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:53:11 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_isprint

_ft_isprint:
	start:
		cmp	rdi,	32
		jl	isnot
		cmp	rdi,	126
		jg	isnot
		jmp	isprint
	isnot:
		mov	rax,	0
		ret
	isprint:
		mov	rax,	rdi
		ret
