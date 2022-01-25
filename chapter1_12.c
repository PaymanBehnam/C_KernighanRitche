#include <stdio.h>
main()
{
    int c,state;
    #define IN 1
    #define OUT 0
    state=IN;
    while ((c=getchar())!=EOF)
    {
	if (c==' '||c=='\t')
	    state=OUT;
	else if(state==OUT)
	    {
	    state=IN;
	    putchar('\n');
	    }
	if (state==IN)
	    putchar(c);
    }
}