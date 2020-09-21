section	.text
		global	ft_strdup
		extern	malloc
		extern	ft_strcpy
		extern	ft_strlen

ft_strdup :
	call	ft_strlen
	push	rdi
	mov		rdi, rax
	add		rdi, 1
	call	malloc
	pop		rsi
	test	rax, rax
	jz		return
	mov		rdi, rax
	call	ft_strcpy
	ret

return :
	ret