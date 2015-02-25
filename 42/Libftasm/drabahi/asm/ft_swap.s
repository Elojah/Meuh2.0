; void		ft_swap(int *a, int *b);

global _ft_swap

_ft_swap:
	mov		rcx, [rdi]
	mov		rdx, [rsi]
	mov		[rsi], rcx
	mov		[rdi], rdx
	ret
