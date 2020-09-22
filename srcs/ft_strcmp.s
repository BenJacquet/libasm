section .text
		global ft_strcmp

ft_strcmp:
	mov rax, 0
	mov rcx, 0
	mov r8, 0

is_equal:
	mov r8b, BYTE [rdi + rcx]
	sub r8b, BYTE [rsi + rcx]
	cmp r8b, 0
	jne return
	cmp BYTE [rdi + rcx], 0
	je return
	cmp BYTE [rsi + rcx], 0
	je return
	inc rcx
	jmp is_equal

return:
	movsx rax, r8b
	ret
