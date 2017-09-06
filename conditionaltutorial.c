#include <stdio.h>

void main()
{
	int n, i;

	n = 15;

	int a[] = {1,3,7,4,754,4567,243,6473,2557,21, 23, 4, 7, 89, 346};

	for (i = 0; i < n; i++)
		printf("%6d%c", a[i], (i%10 ==9 || i ==n-1) ? '\n' : 'A');

}
