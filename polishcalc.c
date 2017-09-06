#include <stdio.h>
#include <stdlib.h>
/* for getop */
#include <ctype.h>

/* for main */
#define MAXOP 	100
#define NUMBER 	'0'

/* for push and pop */
#define MAXVAL 	100 	/*max depth of val stack */

/* for getch and ungetch */
#define BUFSIZE 100			

int sp = 0; 		/* next free stack position */
double val[MAXVAL]; 	/* value stack */

/* for getop */
int getch(void);
void ungetch(int);

/* for main */
int getop(char []);
void push(double);
double pop(void);



/* for getch and ungetch */
char buf[BUFSIZE];	/*buffer for ungetch */
int bufp = 0;		/*next free position in buf */


/* reverse Polish calculator */


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

/*getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; 	/*not a number */
	i = 0;
	if (isdigit(c)) 	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 		/*collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


/*push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double atofmy(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /*skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

main()
{

	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atofmy(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
