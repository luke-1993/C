#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /*outside a word */
#define MAXHIST 15  
#define MAXWORD 11      

/* count lines, words and characters in input*/

void mysolution(){

	int c, nw, state, i, n, t;

	state = OUT;
	nw = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}else if (state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("nw is: %d \n", nw);

	int wordlength[nw];
	for (i = 0; i < nw; ++i)
		wordlength[i] = 0;

	n = 0;
	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			++n;
		} else {
			++wordlength[n];
		}
	}

//printf("word %d" , i(wordlength[i]*'-'));
	i = 0;
	while(i < nw){
		for (t = 0; t < wordlength[i]; ++t){
			printf("-\n");
		}
	printf("\n");
	++i;
	}
}

int answer(){

    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];

    state = OUT;
    nc = 0;         
    ovflow = 0;

    for (i = 0; i < MAXWORD; i++)
        wl[i] = 0;  

    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;            
            if (nc > 0)
            {
                if (nc < MAXWORD)   
                    ++wl[nc];       
                else
                    ++ovflow;       
            }                       
            nc = 0;                 
        }
        else if (state == OUT)
        {
            state = IN;             
            nc = 1;                 
        }
        else
            ++nc;                   
    }

    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
    {
        if(wl[i] > maxvalue)
            maxvalue = wl[i];       
    }

    for(i = 1; i < MAXWORD; ++i)
    {
        printf("%5d - %5d : ", i, wl[i]);
        if(wl[i] > 0)
        {
            if((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }
        else
            len = 0;

        while(len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }

    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);

    return 0;
}

void main(){

	//mysolution();
	answer();
}


