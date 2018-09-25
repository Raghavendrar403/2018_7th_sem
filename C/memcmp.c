#include<stdio.h>
#include<string.h>

int main() {
	int a[] = {1,2,3};
	int b[] = {1,2,3};

	int n = memcmp(a,b,3);
	printf("%d \n",n);
}
