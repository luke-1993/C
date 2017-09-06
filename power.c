#include <stdio.h>

int power(int m, int n), t, i;

power(m,n){
	t = 1;
	for(i = 1; i <= n; ++i){
		t = m*t;
	}	
	return t;

}

main(){

	printf("%d \n", power(3,3));

}


