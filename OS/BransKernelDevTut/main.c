#include<stdio.h>
//#include<system.h>

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

int main() {
	char a[] = "Hello";
	char b[10] ;

	printf("%d \n",strlen(a));
}
