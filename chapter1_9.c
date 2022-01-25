#include <stdio.h>
main ()
{
    int c,flag;
    flag=0;
    while ((c=getchar())!=EOF)
    {
	if (c==' '||c=='\t')
	
	    flag=0;
	else if (flag==0){
	    flag=1;    
	    printf(" ");
	}
	if (flag==1)
	    putchar(c);
    }
    
}	
	
	    
    