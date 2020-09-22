section	.text
		global	_ft_strdup
		extern	_malloc
		extern	_ft_strcpy
		extern	_ft_strlen

_ft_strdup :
	call	_ft_strlen
	push	rdi
	mov		rdi, rax
	inc		rdi
	call	_malloc
	pop		rsi
	cmp		rax, 0
	je		return
	mov		rdi, rax
	call	_ft_strcpy

return :
	ret