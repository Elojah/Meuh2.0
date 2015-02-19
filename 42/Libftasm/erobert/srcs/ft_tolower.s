;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/12 14:07:52 by erobert           #+#    #+#              ;
;    Updated: 2015/02/19 14:51:11 by erobert          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section	.text
	global		_ft_tolower

_ft_tolower:
	start:
		mov		rax,		rdi
		cmp		rdi,		65
		jl		end
		cmp		rdi,		90
		jg		end
		add		rax,		32
		jmp		end
	end:
		ret
