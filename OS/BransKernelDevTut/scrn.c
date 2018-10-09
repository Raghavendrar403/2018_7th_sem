#include<system.h>

unsigned short *textmemptr;		/* where the buffer is located */
int attrib = 0x0F;	/* Background - Black and Foreground - White */
int csr_x = 0, csr_y = 0;

/* Scrolls the screen */
void scroll(void) {
	unsigned blank, temp;	

	/* blank is just space. Give it backcolor */
	blank = 0x20 | (attrib << 8);

	/* row 25 is the end. It means we need to scroll up */
	if(scr_y >= 25) {
		/* Move the current text chuck that makes up the screen 
			back in the buffer by a line */
		temp = csr_y - 25 + 1;
		memcpy(textmemptr, textmemptr + temp * 80, (25-temp) * 80 *2);

		/* Finally we set the chunk of memory that occupies text to our blank character */
		memsetw(textmemptr+(25-temp)*80,blank,80);
		csr_y = 25-1;
	}
}

/* Updates the hardware cursor: the little blinking line
 on the screen under the last character pressed! */

void move_csr(void) {
	unsigned temp;
	/* Index = y*width + x; */
	temp = csr_y*80 + csr_x;

	outportb(0x3D4,14);
	outportb(0x3D5,temp >> 8);
	outportb(0x3D4,15);
	outportb(0x3D5, temp);
}

void cls() {
	unsigned blank;
	int i;
	blank = 0x20 | (attrib << 8);
}
