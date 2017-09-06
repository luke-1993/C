#include <stdio.h>

/*copy input to output; 1st version */
void count2()
{	
	printf("count2\n");
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
	printf("number of characters is %.0f\n", nc);

	printf("-----------------------\n");
}

void count1(){
	
	printf("count1\n");
	double nc = 0;

	while((getchar()) != EOF){
	 	++nc;
		printf("number of characters is %.0f\n", nc);
	}
	printf("-----------------------\n");
}



void main(){

	
	//count2();

	count1();
	

	
}


