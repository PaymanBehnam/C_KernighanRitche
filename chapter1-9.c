#homework 1-9
#include <stdio.h>
main()
{
    int c,flage;
    flage=0;
    while((c=getchar())!=EOF){
	if(c==' '||c=='\t')
	    flage=1;
        else{ 
	    if(flage==1){
		putchar(' ');
		flage=0;}
	    putchar(c);}
    }    	
}

    	






            