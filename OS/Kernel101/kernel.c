
void kmain(void) {
	const char *str = "My first kernel";
	char *vidptr = (char *)0xb8000;	// Video mem begins here
	unsigned int j = 0;
	unsigned int i = 0;

	/* this loop clears the screen 
	 * there are 25 lines each of 80 columns;
	 * each element takes 2 bytes */

	while(j<80*25*2) {
		/* blank character */
		vidptr[j] = ' ';
		vidptr[j+1] = 0xF0;
		j = j+2;
	}

	j = 0;

	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		/* the characters in ascii */
		vidptr[i] = str[j];
		/* black bg and light grey fg */
		vidptr[i+1] = 0xF0;
		++j;
		i = i+2;
	}

	return;
}
