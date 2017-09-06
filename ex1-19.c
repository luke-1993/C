#include <stdio.h>
#define MAXLINE 10000

char line[MAXLINE+1];
char linec[MAXLINE+1];
int getline1(char line[]);
void copy(char to[], char from[], int length);


int getline1(char s[])
{
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[], int length)
{
	int i;

	for(i = 0; i <= length; i ++)
		(to[i]) = (from[length - i]);
}

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = getline1(line) - 1) > 0 ) {
		copy(linec, line, len);
		printf("%s \n", linec);
	}

	return 0;
}


