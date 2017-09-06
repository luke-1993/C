#include <stdio.h>
#define MAXLINE 1000

//int getline1(char line[], int maxline);
//void copy(char to[], char from[]);

//print longest input line

//get line: read a line into s, return length


int getline1(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

//copy: copy 'from' into 'to'; assume to is big enough

void copy(char to[], char from[])
{
	int i, s;
	
	i = 0;
	s = 0;
	while ((from[i]) != '\0'){
		if(from[i] == '\t'){
			to[s] = ' ';
			to[s+1] = ' ';
			to[s+2] = ' ';
			to[s+3] = ' ';
			s += 4;
			++i;
		} else {
			(to[s] = from[i]);
			++i;
			++s;
		}
	}
}

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((len = getline1(line, MAXLINE)) > 0)
		if (len > 0) {
			copy(longest, line);
			printf("%s", longest);
		}

	return 0;
}


