#include<stdio.h>
#include<omp.h>

int main() {
	int a = 0, b = 1, c = 3;
	#pragma omp task
	{
		printf("%d %d %d\n",a,b,c);
		a = a+1;
		b = b+1;
		c = c+1;
	}
	printf("%d %d %d\n",a,b,c);

}
