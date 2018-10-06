;This is the kernels entry point
[BITS 32]
global start	;gloabl tells the linker that start should be available globally
start:
	mov esp, _sys_stack		;This points esp(stack pointer) to our stack area(_sys_stack)
	jmp stublet

ALIGN 4		;Aligns the next instruction at an address multiple of 4
mboot:
	; Multiboot macros that make a few lines later more readable
	MULTIBOOT_PAGE_ALIGN 			equ 1<<0	; left shift 1 by 0
	MULTIBOOT_PAGE_MEMORY_INFO 		equ 1<<1	; 01 << 1 = 10 
	MULTIBOOT_AOUT_KLUDGE			equ 1<<16	
	MULTIBOOT_HEADER_MAGIC 			equ 0x1BADB002 
	MULTIBOOT_HEADER_FLAGS			equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_PAGE_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
	MULTIBOOT_CHECKSUM 				equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
	EXTERN code, bss, end

	; This is GRUB Multiboot header. A boot signature
	; dd is double word
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM
	
	; The linker script fills in data for for these ones
	dd mboot
	dd code
	dd bss
	dd end
	dd start

; This is infinite loop
stublet:
	;extern _main
	; The reason we are using '_' in front of main
	; is because the gcc compiler will put an underscore in front
	; of all function and variable names when it compiles
	;call _main
	jmp $

SECTION .bss
	resb 8192
_sys_stack:

