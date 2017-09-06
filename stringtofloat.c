#include <ctype.h>
#include <stdio.h>

double atofsci(char s[])
{
	double val, power, base;
	int i, sign, powerval, powervalue, exponent;

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
	if (s[i] == '\0')
		return sign * val / power;
	while (s[i] != '\0') {
		if (s[i] == 'e' || s[i] == 'E')
			i++;
		base = (s[i] == '-') ? 0.1 : 10;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if(isdigit(s[i])) {
			powerval++;
			i++;
		}
		else
			break;
	}
	

	int k;
	for(k = 0; k < powerval; k++) {
		exponent *= base;
	}	
	return sign * val / power * exponent;
}

double atof(char s[])
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

int atoi(double s)
{
	return (int) s;
}

int main(void)
{
	char t[] = "-12.3e+10";
	double a;
	a = atofsci(t);
	printf("floatsci result is = %f\n", a);
	int p;
	p = atoi(a);
	printf("int result is = %d\n", p);
	
}

int returnofchars(char str[], int length)
{
	int i;
	int res;
	for(i = 0; i < length; i++){
		res = isspace(str[i]);
		printf("res is %d\n", res);
	}
}
