;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/17 16:57:42 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:21:37 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_memset

_ft_memset:
	start:
		push	rdi
		cmp		rsi,	byte 0
		je		end
		mov     rcx,	rdx
		mov     rax,	rsi
		cld
		rep		stosb
		jmp		end
	end:
		pop		rax
		ret
