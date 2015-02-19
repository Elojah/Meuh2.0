;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/11 21:59:38 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:51:32 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section	.text
	global		_ft_toupper

_ft_toupper:
	start:
		mov		rax,		rdi
		cmp		rdi,		97
		jl		end
		cmp		rdi,		122
		jg		end
		sub		rax,		32
		jmp		end
	end:
		ret
