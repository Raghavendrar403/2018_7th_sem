#define EOI 			0		/* end of the input 			*/
#define SEMI 			1 		/* 			; 					*/
#define PLUS			2 		/* 			+ 					*/
#define MINUS 			3 		/* 			-					*/
#define TIMES			4 		/* 			*					*/
#define LP				5		/* 			(					*/
#define	RP				6		// )
#define NUM_OR_ID		7		// decimal number or identifier 

extern char *yytext;	// points to the current lexeme
extern int yyleng;		// number of characters in the lexeme pointed by yytext
extern int yylineno;	// current line number in the input file

