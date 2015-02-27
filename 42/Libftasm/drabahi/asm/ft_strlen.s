; size_t	ft_strlen(const char *s)

global	_ft_strlen

_ft_strlen:
	mov			rcx, 0
	mov			rax, 0
	not			rcx
	repne scasb
	not			rcx
	dec			rcx
	mov			rax, rcx
	ret
