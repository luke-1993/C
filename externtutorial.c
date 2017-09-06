#include <stdio.h>
#include <stdlib.h>

extern int * pvar;
int main(void)
{
	pvar = malloc(1*sizeof(int));
	*pvar = 10;
	return 0;
}
