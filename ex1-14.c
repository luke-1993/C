#include<stdio.h>

mysolution(){
	int characters[36], t, c, i;

	for(i=0; i<10; ++i){
		characters[i] = 0;
	}

	while(c=getchar() != EOF){
		++characters[c-32];
	}

	for(t = 0; characters[t] != 0; t++)
	{
		printf("frequency of %d is : %d \n", t, characters[t]);
	}

}

answer(){
  int charcount[95],c,i=0,max=0;
  for(i=0;i<95;++i) /*Setting every array point to zero*/
    {
      charcount[i]=0;
    }
  while((c=getchar())!=EOF) /*Frequency of each character*/
    {    
      ++charcount[c-32];
    }
  for(i=0;i<95;++i) /*For character count of the longest word*/
    {
      if(max<charcount[i])
    max=charcount[i];
    }
  printf("\n");
  for(i=max;i>=0;--i) /*Printing the Vertical Histogram*/
    {
      for(c=0;c<95;++c)
    {
      if(charcount[c]!=0)
        {
          if((charcount[c]-i)<0)
        {
          printf("  ");
        }
          else if(i==0)printf("==");
          else printf(" X");
        }
    }
      printf("\n");
    }
  for(i=0;i<95;++i) /*Printing the Characters below the Histogram for reference*/
    {
      if(charcount[i]!=0)
    {
      if(i==0)printf("sp "); /*We would write "sp" that stands for space*/
      else printf("%c ",i+32);
    }
    }
  printf("\n");
}


main()
{
	//answer();
	mysolution();
}
