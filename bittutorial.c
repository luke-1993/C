#include <stdio.h>

/* bitcount: count num of 1 bits in x */

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;

}

/* getbits: get n bits from position p */


unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}


void main(){

unsigned value1;
int value2;
int value3;
unsigned result;
int numOfBits;

value1 = 31;
numOfBits = bitcount(value1);
//value2 = 5;
//value3 = 3;


	//result = getbits(value1, value2, value3);
	//printf("result is: %u \n", result);

	printf("num of 1bits in %d is %d \n", 
value1, 
numOfBits);

}
