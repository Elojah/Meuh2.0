;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/17 13:50:18 by erobert           #+#    #+#              ;
;    Updated: 2015/02/17 16:51:32 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global		_ft_strcat

_ft_strcat:
	start:
		mov		rax,		rdi
		jmp		len
	len:
		cmp		[rdi],		byte 0
		je		loop
		inc		rdi
		jmp		len
	loop:
		cmp		[rsi],		byte 0
		je		end
		mov		r11,		[rsi]
		mov		[rdi],		r11
		inc		rdi
		inc		rsi
		jmp		loop
	end:
		ret
