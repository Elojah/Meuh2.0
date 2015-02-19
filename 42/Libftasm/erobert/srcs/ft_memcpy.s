;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/17 18:48:48 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:21:11 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_memcpy

_ft_memcpy:
	start:
		mov		rax,	rdi
		mov		rcx,	rdx
		cld
		rep		movsb
		ret
