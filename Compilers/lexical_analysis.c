#include "lexical_header.h"
char buffer[20];

int scanner() {
	int ch;

	while(ch = getchar()) {
		if(isalpha(ch)) {
			memset(buffer,0,sizeof(char)*20);
			char *a = buffer;
			*a++ = ch;
			while((*a=getchar()) && (!isspace(*a))) {
				a++;
			}	
			*a = '\0';
			printf("%s\n",buffer);
		}
	}
	return 0;
}
