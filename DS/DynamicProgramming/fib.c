#include<stdio.h>

int main() {
	int s[10];
	int a = 0;
	int b = 1;
	int n = 0;
	scanf("%d",&n);
	s[0] = a+b;
	s[1] = s[0] + b;

	int i = 0;
	for(i = 2; i<=n; i++) {
		s[i] = s[i-1] + s[i-2];
	}

	for(int i = 0; i<=n; i++) {
		printf("%d ",s[i]);
	}
}
