#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);

/* for getch and ungetch */
char buf[BUFSIZE];	/*buffer for ungetch */
int bufp = 0;		/*next free position in buf */


/* getch and ungetch */
int getch(void) 	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}

/*getint: get next intereger from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) /*skip white*/
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);     /*not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

/*
int fillArray() {
	int n, array[10], getint(int *);

	for (n = 0; n < 10 && getint(&array[n]) != EOF; n++)
		;
	return 0;
}
*/
int main(){

	int n = 12;
	int a = 0;
	a = getint(&n);
	printf("a = %d\n", a);

	printf("n = %d\n", n);
}

