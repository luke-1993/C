#include <stdio.h>
#define ALLOCSIZE    10 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage fo alloc */
static char *allocp = allocbuf; /* next free position
				and equivalent to
				*allocp = &allocbuf[0]
				since array name is address of 0th element */

char *alloc(int n) /* return pointer to n characters */
{

    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else         /* not enough room */
        return 0;
}

void afree(char *p) /* free sotrage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int mystrcmp(char *s, char *t)
{

    for( ; *s = *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

int strend(char *s, char *t)
{
    int tlen;
    int slen;
    int j;
    tlen = 0;
    slen = 0;
    while(*s++)
	slen++;
    while(*t++)
        tlen++;
    t -= 1;
    s -= 1;
    for(j = 0; j < tlen + 1; j++) {
        if(*t != *s)
             return 0;
    s--;
    t--;
    }
    return 1;
}

int main()
{

    char str1[] = "testtest";
    char str2[] = "test";
    int a = strend(str1, str2);
    char * space = alloc(3);
    printf("contents of space = %c \n\n", *space);
    printf("strend = %d \n\n", a);
    return 0;
}
