section	.text
		global ft_strlen

ft_strlen :
	mov rax, 0

is_null :
	cmp BYTE [rdi + rax], 0
	je return
	inc rax
	jmp is_null

return :
	ret
