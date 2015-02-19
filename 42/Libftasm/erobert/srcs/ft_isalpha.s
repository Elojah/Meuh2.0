;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 20:56:18 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:50:52 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_isalpha

_ft_isalpha:
	start:
		cmp		rdi,	65
		jl		isnot
	    cmp		rdi,	122
	    jg		isnot
	    cmp		rdi,	90
	    jle		isalpha
	    cmp		rdi,	97
	    jge		isalpha
	isnot:
		mov		rax,	0
		ret
	isalpha:
		mov		rax,	1
		ret
