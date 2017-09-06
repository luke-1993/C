#include <stdio.h>

/*copy input to output; 1st version */



void main(){

	printf("-----------------------\n");


	double c;
	int n1 = 0;

	while((c =getchar()) != EOF){
		if (c == ' '){
			++n1;
		}
	printf("number of new lines is %d\n", n1);
	}
	


	printf("-----------------------\n");
}


