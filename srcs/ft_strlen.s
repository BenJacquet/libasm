section	.text
		global ft_strlen

ft_strlen:
	mov rax, 0

check:
	cmp BYTE [rdi + rax], 0
	je return
	inc rax
	jmp check

return:
	ret
