section	.text
		global _ft_write
		extern ___error

_ft_write :
	mov		rax, 0
	syscall
	jb		error
	ret

error :
	push	rax
	call	___error
	pop		r9
	mov		[rax], r9
	mov		rax, -1

return :
	ret