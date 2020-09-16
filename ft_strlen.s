section	.text
		global _ft_strlen

_ft_strlen :
	mov rax, 0

is_null :
	cmp BYTE [rdi + rax], 0
	je return
	inc rax
	jmp is_null

return :
	ret
