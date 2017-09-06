#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /*outside a word */

/* count lines, words and characters in input*/
main(){

	int c, nl, nw, nc, state;


	while ((c = getchar()) != -1){
		++nc;
		if (c == ' ' || c == '\n' || c == '\t'){
			c = '\n';
			putchar(c);
		}
		else {
			putchar(c);
		}
	
	}
}
