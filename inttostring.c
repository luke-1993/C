#include <stdio.h>

/*i itoa: convert n to characts in s */

/* printd: print n in decimal */

void recitoa(int n, char s[], int i)
{
	int sign;

	if ((sign = n) < 0)
		n = -n;
	//s[i++] = n % 10;
	if(n / 10)
		recitoa(n/10, s, ++i);
	s[i] = (n % 10 + '0');
	if(n / 10 == 0)	
	s[++i] = '\0';
}

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	printf("result = %s", s);
}

int main(){

	int n = 635;
	char s[4];
	int i = 0;
	recitoa(n, s, i);
	printf("result = %s \n", s);

}
