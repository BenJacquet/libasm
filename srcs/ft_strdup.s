section	.text
		global	ft_strdup
		extern	malloc
		extern	ft_strcpy
		extern	ft_strlen

ft_strdup:
	call	ft_strlen
	push	rdi
	mov		rdi, rax
	inc		rdi
	call	malloc
	pop		rsi
	cmp		rax, 0
	je		return
	mov		rdi, rax
	call	ft_strcpy

return:
	ret