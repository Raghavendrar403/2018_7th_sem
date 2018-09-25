#include<stdio.h>

void x(char s[static 1]) {
	printf("-- %s\n",s);
}

int main() {
	char s[] = "";	
	x(s);
}
