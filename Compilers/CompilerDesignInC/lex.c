#include "lex.h"
#include<stdio.h>
#include<ctype.h>

char 		*yytext = "";		/* Lexeme (not '\0' terminated) */
int 		yyleng = 0;
int 		yylineno = 0;

void lex() {
	static char input_buffer[128];
	char 		*current; 		/* points to a character taken from input */

	current = yytext + yyleng;	/* skip the current lexeme */

	while(1) {
		while(!current)	 {
			/* Get new lines, skipping any leading white space on the line,
			 * until a nonblank line is found
			 */
			
			current = input_buffer; 	/* point to the start of the input buffer */
			if( !gets(input_buffer) ) {	/* if reached EOF */
				*current = '\0';
				return EOI;
			}

			++yylineno;	/* at the beginning will be line no 1 */
			
			while(isspace(*current))	/* skip all the whitespaces */
				++current;
		}

		for( ; *current; ++current) {
			/* Get the next token */
			yytext = current;
			yyleng = 1;

			switch(*current) {
				case EOF:	return EOI;
				case ';':	return SEMI;
				case '+':	return PLUS;
				case '-':	return MINUS;
				case '*':	return TIMES;
				case '(':	return LP;
				case ')':	return RP;

				case '\n':
				case '\t':
				case ' ' :	break;
			}
		}
	}
}

