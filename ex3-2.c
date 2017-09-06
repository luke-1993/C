#include <stdio.h>

void shellsort1(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i-gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;

			}
}

int main(){

	char s[] = {'H', 'e', '\\', 'l', 'l' , 'o', 'a', '\n', '\n', '\0'};

	int v[] = {10, 15, 3, 20, 100 , 1, 56, 9, 89, 70};
	
	int i;
	for(i = 0; i < 10; i ++)
		printf("%d\n", v[i]);
	
	shellsort1(v, 10);

	for(i = 0; i < 10; i ++)
		printf("%d\n", v[i]);

	

}


