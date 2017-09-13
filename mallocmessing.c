#include <stdio.h>
#include <stdlib.h>

int main() {

	int *pOfInts;

	int numberOfProducts;
	//*pOfInts = 1;
	//printf("address of pOfInts is %p\n\n", &pOfInts);

	//printf("value of pOfInts is %d\n\n", *pOfInts);

	int primeNumbers[] = {2,3,5,7};

	*(primeNumbers + 1) = 4;
	printf("First index : %d \n\n", *(primeNumbers + 1));

	printf("First index : %d \n\n", primeNumbers[1]);

	pOfInts = (int *) malloc(1 * sizeof(int));

	*pOfInts = 1;

	*(pOfInts + 1) = 2;

	*(pOfInts + 100) = 3;

	printf("pOfInts is %p \n\n", pOfInts);

	printf("pOfInts is %d \n\n", *(pOfInts + 100));

	int i;
	for(i = 0; i < 10; i++){

		int a = scanf("%d",&numberOfProducts);
		printf("%d\n", a);
	}
}
