#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
	int n;
	char s[100];
	
	for (int i = 2; i <= 20; i++) {
		itob(255, s, i);
		printf("decimal 255 in base %-2d : %s\n", i, s);
	}
	
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign, r;
	
	sign = n;
	i = 0;
	do {
		r = n % b;
		if (sign < 0)
			r = -r;
		s[i++] = (r > 9 ? (r-10 + 'A') : (r + '0'));
	} while (n /= b);
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	
	reverse(s);
}

void reverse(char s[])
{
	int i, j, t;
	
	for (j = 0; s[j] != '\0'; j++)
		;
	for (i = 0, --j; j > i; i++, j--) {
		t = s[j];
		s[j] = s[i];
		s[i] = t;
	}
}

