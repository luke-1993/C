#include <stdio.h>
#include <stdlib.h>

//to get the address of the variable use &]
//to access data within the address use *


void random123Main(){

	int rand1 = 0, rand2 = 0;

	printf("Main before function call  \n\n");

	generateTwoRandomNums(rand1, rand2);

	printf("rand1 = %d \n\n", rand1);
	printf("rand2 = %d \n\n", rand2);

	pointerRandomNumbers(&rand1, &rand2);

	printf("Main before function call  \n\n");

	printf("rand1 = %d \n\n", rand1);
	printf("rand2 = %d \n\n", rand2);

}

void pointerRandomNumbers(int* rand1, int* rand2){
	
	*rand1 = rand() % 50 + 1; //assign
	*rand2 = rand() % 50 + 1;

	printf("New rand1 in func = %d \n\n", *rand1);
	printf("New rand2 in func = %d \n\n", *rand2); //retrieve

}

void generateTwoRandomNums(int rand1, int rand2){
	
	rand1 = rand() % 50 + 1;
	rand2 = rand() % 50 + 1;

	printf("New rand1 in func = %d \n\n", rand1);
	printf("New rand2 in func = %d \n\n", rand2);

}


void pointerStuff(){

	int rand1 = 12, rand2 = 15;

	printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);

	//printf("rand1 = %f : rand2 = %f\n\n", &rand1, &rand2);

	printf("Size of int %zu \n\n", sizeof(rand1));

	int * pRand1 = &rand1;

	printf("Pointer %p\n\n", pRand1);

	//printf("Pointer %d\n\n", pRand1);

	printf("Value %d\n\n", *pRand1);

	int i;
	char * students[4] = {"Sally", "Mark", "Paul", "Sue"};

	for(i=0; i < 4; i++){
	
		printf("%s : %p\n\n", students[i], &students[i]);	

	}

}

void pointerArithmetic(){

	int primeNumbers[] = {2,3,5,7};

	printf("First index : %d \n\n", *(primeNumbers + 1));

}

void editMessageSent(char* message, int size){

	int i;
	char newMessage[] = "New Message";
	
	if(size > sizeof(newMessage)){

		for(i = 0; i < sizeof(newMessage); i++){

			message[i] = newMessage[i];
		}
	} else {

		printf("New message is too big \n\n");
	}
}

void main(){
	
	/*char randomMessage[] = "edit my function";

	editMessageSent(randomMessage, sizeof(randomMessage));

	printf("New message: %s \n\n", randomMessage); */

	pointerArithmetic();

}




