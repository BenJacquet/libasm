section	.text
		global ft_write
		extern __errno_location

ft_write :
	mov		rax, 0
	syscall
	jb		error
	ret

error :
	push	rax
	call	__errno_location
	pop		r9
	mov		[rax], r9
	mov		rax, -1

return :
	ret