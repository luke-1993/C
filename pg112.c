#include <stdio.h>

int daytab[2][13] = { 
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int printArray(int (*array)[13])
{
	int i;
	int j;
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 13; j++)
		{	
		printf("%d\n", daytab[i][j]);
		}
	}
	return 0;
}

int main()
{
	printArray(daytab);
	return 0;
}
