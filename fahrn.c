#include <stdio.h>

void main(){

float fahr;
float celsius;
int step = 20;

for(fahr = 300; fahr >= 0; fahr -= 20){

	printf("%3.0f in cel: %10.1f \n",fahr, (5)*(fahr - 32) / 9);

	}
}
