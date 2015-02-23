;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 19:13:03 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:20:43 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_strlen

_ft_strlen:
	start:
		push	rdi
		mov		rax,		0
		mov		rcx,		0
		not		rcx
		cld
		repne	scasb
		not		rcx
		dec		rcx
		mov		rax,		rcx
		pop		rdi
		ret
