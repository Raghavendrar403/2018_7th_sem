read_port:
	; The arguments to this function is the port number to read from
	mov edx, [esp + 4]		; All the arguments to the function are pushed on the stack
	; The in will read a byte into al from port number in dx
	in al, dx				; The dx reg is lower 16 bits of eax reg d
	ret						; return function returns the value held in eax reg

write_port:
	; The arguments to this function is the port number
	; and the data to be written
	mov edx, [esp + 4]
	mov al, [esp+4+4]
	out dx, al				; Output byte in al to IO port address in dx
