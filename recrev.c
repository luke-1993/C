#include <stdio.h>
#define	max(A, B) ((A) > (B) ? (A) : (B))
#define forever for (;;)

int rreverse(char s[], int i)
{
	if(i != -1) {
		putchar(s[i--]);
		rreverse(s, i);
	}
	else
		return 0;
}


int main(){

	char s[] = "hello";
	//rreverse(s, 5);
	int a;
	a = max(4,5);
	forever;
	printf("%d\n", a);

}
