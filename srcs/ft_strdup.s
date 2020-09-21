section	.text
		global	_ft_strdup
		extern	_malloc
		extern	_ft_strcpy
		extern	_ft_strlen

_ft_strdup :
	call	_ft_strlen
	push	rdi
	mov		rdi, rax
	add		rdi, 1
	call	_malloc
	pop		rsi
	test	rax, rax
	jz		return
	mov		rdi, rax
	call	_ft_strcpy
	ret

return :
	ret