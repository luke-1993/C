#include <stdio.h>

/*copy input to output; 1st version */
void print(){
	int c;

	while ((c = getchar()) != EOF){ //here EOF is a symbolic constant for an integer
		putchar(c);

	}
}

void main(){

	printf("EOF is = %d \n", EOF);
	
	//print();

	

	
}


