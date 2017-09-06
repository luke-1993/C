#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main()
{

    int i;
    i = 3 == 4;
    printf("%d\n\n", i);
}

/* sort input lines */
main1()
{
    int nlines;		/* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
	writelines(lineptr, nlines);
	return 0;
    } else {
	printf("error: input too big to sort\n");
	return 1;
    }
}


#define MAXLEN 1000	/* max length of any input line */
int mygetline(char *, int);
char *alloc(int);

char *alloc(int n)
{
     return 0;
}

/*readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
	if (nlines >= maxlines || (p = alloc(len)) == NULL)
	    return -1;
	else {
	    line[len - 1] = '\0';	/*delete newline */
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i = 0; i < nlines; i++)
	printf("%s\n", lineptr[i]);
}

/* getline: get line into s, return length */
int mygetline(char *s, int lim)
{
    char *p;
    int c;

    p = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *p++ = c;
    if (c == '\n')
        *p++ = c;
    *p = '\0';
    return (int)(p - s);
}

