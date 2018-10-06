kernel.bin: start.o main.o link.ld 
	ld -T link.ld -o kernel.bin start.o

main.o: main.c
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./Include -c -o main.o main.c

start.o: start.asm
	nasm -f elf64 -o start.o start.asm

clean:
	rm start.o kernel.bin main.o
