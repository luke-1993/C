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

int copy(char to[], char from[], char brackets[])
{
	int i, n, t;
	
	n = 0;
	i = 0;
	t = 0;
	while ((from[i]) != '\0'){
		to[i] = from[i];
		
		if(from[i] != '\n'){
			++n;
                        if(n > 80 && from[i] == ' '){
			to[i] = '\n';
			n = 0;
			}
		}else if(from[i] == '\n')
			n = 0;
		if(from[i] == '{' || from[i] == '(' || from[i] == '[' || from[i] == '}' || from[i] == ')' || from[i] == ']'){
			brackets[t] = from[i];
			brackets[t+1] = '\0';
			++t;
		}
		++i;
				
	}
	to[i+1] = '\0';
	return t;
}

int brackcheck(char bracketcheck[], int i)
{
		int s = 1;
		
		while((bracketcheck[i] == '{' || bracketcheck[i] == '(' || bracketcheck[i] == '[' || bracketcheck[i] == ' ') && 			(bracketcheck[i+s] == ' ' || bracketcheck[i+s] == '{' || bracketcheck[i+s] == '(' 
			|| bracketcheck[i+s] == '[')){
			++s;
		} 
		if(bracketcheck[i] == '{' && bracketcheck[i+s] == '}'){
			bracketcheck[i] = ' ';
			bracketcheck[i+s] = ' ';
			return 0;
		}else if(bracketcheck[i] == '(' && bracketcheck[i+s] == ')'){
			bracketcheck[i] = ' ';
			bracketcheck[i+s] = ' ';
			return 0;
		}else if(bracketcheck[i] == '[' && bracketcheck[i+s] == ']'){
			bracketcheck[i] = ' ';
			bracketcheck[i+s] = ' ';
			return 0;
		}else{
			return 1;
		}

}

int main()
{
	int len;
	int max;
	int numOfBrackets;
	char line[MAXLINE];
	char linemod[MAXLINE];
	char brackets[MAXLINE];
	int i;
	int value;
	
	len = getline1(line, MAXLINE);
	
	if(len > 0)
	numOfBrackets = copy(linemod, line, brackets);

	printf("%s", linemod);

	i = 0;

	while(i < numOfBrackets){
		printf("------------------------------ \n");
		printf("brackets: %s \n", brackets);	
		//brackcheck(brackets, i);
		value = brackcheck(brackets, i);
		if(value == 0){
			printf("RESET \n");
			printf("brackets: %s \n", brackets);
			i = 0;
		}else if(value == 1)
			++i;
	}

	printf("brackets after: %s \n", brackets);


	//printf("%s, length = %d \n", line, len);

	//printf("%s, length = %d \n", longest, len);
		
	return 0;
}


