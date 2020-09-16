section	.text
		global _ft_strcpy

_ft_strcpy :
	mov rax, 0
	mov rcx, 0

copy :
	mov	r8b, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], r8b
	cmp	r8b, 0
	je	return
	inc	rcx
	jmp	copy

return :
	mov rax, rdi
	ret