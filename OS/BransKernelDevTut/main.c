#include<system.h>

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count) {	
	unsigned int i = 0;
	for(i = 0; i<count; i++) {
		dest[i] = src[i];
	}
	return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count) {
	int i = 0;
	for(i = 0; i<count; i++) {
		dest[i] = val;	
	}

	return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count) {
	int i = 0;
	for(i = 0; i<count; i++) {
		dest[i] = val;	
	}
	return dest;
}

int strlen(const char *str) {
	int i = 0;
	while(str[i] != '\0') {
		i++;
	}
	return i;
}

/* This will be used to read from IO ports to get data
from devices such as keyboard */
unsigned char inportb(unsigned short _port) {
	unsigned char rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

/* This will be used to write to IO ports to send bytes
to deivces */
void outportb (unsigned short _port, unsigned char _data) {
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));	
}

/* The main contains an infinite loop that does nothing */
int main() {
	for(;;);
}
