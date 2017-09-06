#include <stdio.h>

/*copy input to output; 1st version */

void main(){

	int c;
	int tab = 9;
	int space = 32;
	int backspace = 92;

	for (c = getchar();c != EOF; c = getchar()){ 
		//printf("ASCII value of character %c is %d \n\n", putchar(c), c);
		if(c == '\t'){
			putchar(92);
			putchar('t');
		} else
		putchar(c);

	}

}


