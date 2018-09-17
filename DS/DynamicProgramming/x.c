#include<stdio.h>
#include<string.h>
int check_even(char a) {
	int num = a - '0';
	return !(num&1);
}

int main() {
	char string[10];
	scanf("%s",string);
	int s[strlen(string)+1];
	int n = strlen(string);
	s[n] = 0;
	int i = 0;
	for(i = n-1; i>=0;  i--) {
		s[i] = check_even(string[i]) + s[i+1];
	}

	for(int i = 0; i<n; i++) {
		printf("%d ",s[i]);
	}
	printf("\n");
}
