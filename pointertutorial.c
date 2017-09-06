#include <stdio.h>

int ex6() {

   const int MAX = 3;

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have address of the first element in pointer */
   ptr = var;
   i = 0;
	
   while ( ptr <= &var[MAX - 1] ) {

      printf("Address of var[%d] = %p\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* point to the previous location */
      ptr++;
      i++;
   }
	
   return 0;
}

int ex5() {

   const int MAX = 3;

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have array address in pointer */
   ptr = &var[MAX-1];
	
   for ( i = MAX; i > 0; i--) {

      printf("Address of var[%d] = %p\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* move to the previous location */
      ptr--;
   }
	
   return 0;
}

int ex4() {

   const int MAX = 4;

   char  var[] = {'A', 'B', 'C'};
   int  i;
   char *ptr;

   /* let us have array address in pointer */
   ptr = var;
	
   for ( i = 0; i < MAX; i++) {

      printf("Address of var[%d] = %p\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* move to the next location */
      ptr++;
   }
	
   return 0;
}

int ex3() {

	int *ptr = NULL;

	printf("address of ptr is: %p\n", ptr);

	printf("Value of ptr is: %d\n", *ptr);

	return 0;

}

int ex2() {
	
	int var = 20;
	int *ip; //pointer var declaration

	ip = &var;

	printf("Address of var: %p \n", &var );

	printf("address stored in ip pointer variables: %p\n", ip);

	printf("value of *ip variable: %d\n", *ip);

	return 0;
}

int ex1() {

	int *var1;
	char var2[10];

	printf("address of var1: %p\n", var1);
	printf("address of var2: %p\n", &var2);

	return 0;
}

double getAverage(int *arr, int size) {

   int  i, sum = 0;       
   double avg;          
 
   for (i = 0; i < size; ++i) {
      sum += *(arr +i);
   }
 
   avg = (double)sum / size;
   return avg;
}
 
int main () {

   /* an int array with 5 elements */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   /* pass pointer to the array as an argument */
   avg = getAverage( balance, 5 ) ;
 
   /* output the returned value  */
   printf("Average value is: %f\n", avg );
   return 0;
}

