#include <stdio.h>
#include <string.h>
#include <math.h>
main()
{
    int c,j,i=0,k=0,h=0,x;
    int list[4];
    int s[4];
	for (i=0;i<=3;++i)
	{
	    list[i]=0;
	    s[i]=0;
	}
    i=0;
    while ((c=getchar())!= EOF)
	list[i++]=c;
    j=0;
    while (j<power(2,i))
    {
	x=j;
	while(x>=0) 
	{
	    s[k++]=(x&1);
	    x=(x>>1);
	}
	printf ("{");
	for (h=0;h<=k;++k)
	{
	    if (s[h]==1)
		printf ("%d",list[h]);
	}
	printf("}");	        
	j++;
    }    
}
