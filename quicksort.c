#include <stdio.h>


/* qsort: sort v[left]...v[right] into increasing order */

void qsort(int v[], int left, int right)
{

	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right) /* do nothing if array contains */
		return;    /* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
	last = left;			 /* to v[0] */
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */	
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int main() 
{
	int v[] = {31 , 28, 1, 50, 16, 99, 3, 6, 5, 9, 11, 2};
	qsort(v, 0 , 11);

	int i;
	for(i = 0; i < 12; i++)
		printf("%d \n", v[i]);
}
