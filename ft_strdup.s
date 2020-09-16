section	.text
		global	_ft_strdup
		global	_ft_malloc
		extern	_malloc
		extern	_ft_strcpy
		extern	_ft_strlen


_ft_malloc :
	call	_ft_strlen
	mov		rsi, rdi
	mov		rdi, rax
	add		rdi, 1
	push	rdi
	;push	rsi
	call	_malloc
	;pop		rsi
	pop		rdi
	;mov		rdi, rax
	;call	_ft_strcpy
	ret
_ft_strdup :
	;call	_ft_strlen
	;mov		rsi, rdi
	;mov		rdi, rax
	;add		rdi, 1
	;call	_malloc
	;mov		rdi, rax
	;call	_ft_strcpy

return :
	ret