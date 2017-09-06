#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER   1024
#define SPACE        ' '
#define TAB          '\t'

int CalculateNumberOfSpaces(int Offset, int TabSize)
{
   return TabSize; //- (Offset % TabSize);
}

/* K&R's getline() function from p29 */
int getline1(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

int main(void)
{
  char  Buffer[MAX_BUFFER];
  int TabSize = 4; /* A good test value */

  int i, j, k, l, space, newline, character, tab;
  int lineofspace;
  lineofspace = 0;
  newline = 0;
  character = 0;
  space = 0;
  tab = 0;

  while(getline1(Buffer, MAX_BUFFER) > 0)
  {
    for(i = 0, l = 0; Buffer[i] != '\0'; i++)
    {
      if(Buffer[i] == SPACE){
          space++;
      }else if( Buffer[i] == TAB){
	  tab++;
      }else if(Buffer[i] == '\n'){
	  if((character == 0) && (space != 0)){
	  	lineofspace = 1;
	  }
      character = 0;
      } else {
	  character++;
      }
      if(lineofspace == 1)
      {
	if(SPACE>3){
	  putchar(SPACE/3)
	}
        j = CalculateNumberOfSpaces(l, TabSize);
	printf("here");
        for(k = 0; k < j; k++)
        {
          putchar(SPACE);
          l++;
        }
      }
      else
      {
        putchar(Buffer[i]);
        l++;
      }
    }
  }

  return 0;
}
