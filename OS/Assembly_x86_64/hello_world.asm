section .data
	text db "Hello World!",10

section .text
	global _start

_start:
	mov rax, 1	; 1 is the code for sys_write
	mov rdi, 1	; 0 - ip, 1 - op, 2 - error
	mov rsi, text
	mov rdx, 14 ; length of the string
	syscall		; call the system call sys_write

	mov rax, 60	;sys_exit
	mov rdi, 0	; error code
	syscall

