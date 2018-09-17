#include<stdio.h>
#include<stdlib.h>

int main() {
	size_t c;
	int a = 10;
	int b = 10;

	c = (a<=b) + (a == b) + (a>=b);

	printf("%zu\n",c);
}
