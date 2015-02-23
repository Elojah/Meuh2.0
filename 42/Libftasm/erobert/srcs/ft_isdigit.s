;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 21:18:54 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:52:58 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_isdigit

_ft_isdigit:
	start:
		cmp	rdi,	48
		jl	isnot
		cmp	rdi,	57
		jg	isnot
		jmp	isdigit
	isnot:
		mov	rax,	0
		ret
	isdigit:
		mov	rax,	1
		ret
