#include <stdio.h>
int power(int base,int n)
{
    int i,p;
    p=1;
    for (i=1;i<=n;++i)
	p=p*base;
    return p;
}
main()
{
    int c,i,j,sum,total;
    int digit[1000];
    i=sum=total=0;
    while ((c=getchar())!=EOF)
    {
	while (c!='\n')
	{
	    while (c!=',')
	    {
		digit[i]=c;
		++i;
	    }
	    j=i-1;
	    i=0;
	    while (j>=0)
	    {
		sum=sum+digit[i]*power(10,j);
		++i;
		--j;
	    }
	    total=total+sum;
	    sum=0;
	    i=0;
	}
	printf("%d\n",total);
	total=0;
    }
}
	
	    
		
    