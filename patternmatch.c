#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";


/*find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;
	int i;

	while (getline1(line, MAXLINE) > 0)
		if ((i = strindexr(line, pattern)) >= 0) {
			printf("%s", line);
			printf("at index %d", i);
			found++;
		}
	return found;
}

/*getline: get line into s, return length */
int getline1(char s[], int lim)
{

	int c, i;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{

	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j] == t[k]; j++, k++)
			;

		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

/* strindex: return index of rightmost occurence of t in s, -1 if none */
int strindexr(char s[], char t[])
{

	int i, j, k;
	int index;

	index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		j=i; 
		k=0;
		while(t[k]!='\0' && s[j] == t[k]) {
			j++;
			k++;
		}

		if (k > 0 && t[k] == '\0') {
			printf("i is %d \n", i);
			printf("k is %d \n", k);
			index = i + k;
			//printf("index is %d \n", index);
		}
	}
	printf("index is %d \n", index);
	return index;
}
