/*
write program to fold long input lines into two or more shorter lines after last non-blank character that occurs before the n-th column of input
*/
#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF 70

//int getline1(char line[], int maxline);
//void copy(char to[], char from[]);

//print longest input line

//get line: read a line into s, return length


int getline1(char s[], int lim)
{
	int c, i, n;

	n = 0;
	

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;

	s[i] = '\0';
	return i;
}

//copy: copy 'from' into 'to'; assume to is big enough

void copy(char to[], char from[])
{
	int i, n;
	
	n = 0;
	i = 0;
	while ((from[i]) != '\0'){
		to[i] = from[i];
		
		if(from[i] != '\n')
			++n;
                        if(n > 20 && from[i] == ' '){
			to[i] = '\n';
			n = 0;
		}
		else if(from[i] == '\n')
			n = 0;
		
		++i;
				
	}
}

int main()
{
	int i;
	int len;
	int max;
	char line[MAXLINE];
	char linemod[MAXLINE];
	
	len = getline1(line, MAXLINE);
	
	i = 0;
	if(len > 0)
	copy(linemod, line);

	printf("%s", linemod);


	//printf("%s, length = %d \n", line, len);

	//printf("%s, length = %d \n", longest, len);
		
	return 0;
}


