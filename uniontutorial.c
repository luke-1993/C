//another change
#include <stdio.h>
#include <string.h>
 
typedef union{
   int i;
   float f;
   char str[20];
} Data1;
 
int main( ) {      

   Data1 data;
   int a;
   a = 3;
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

   return 0;
}
//random comment
