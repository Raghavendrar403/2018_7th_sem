#include<stdio.h>

int main() {
	char input_buffer[128];

	gets(input_buffer);
	prinf("%s\n",input_buffer);
}
