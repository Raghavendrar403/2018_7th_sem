bits 32			; nasm directive to make sure object file is 64-bit
section .text
	; multiboot spec
	align 4
	dd 0x1BADB002		; magic number
	dd 0x00				; flags
	dd - (0x1BADB002 + 0x00)	; checksum m+f+c should be zero
	
global start
extern kmain


start:
	cli			; (clear interrupts) block interrupts
	mov esp, stack_space
	call kmain
	hlt			; halt the CPU


section .bss
resb 8192		; 8KB for stack space
stack_space:
