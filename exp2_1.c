#include <stdio.h>
main()
{
    int c,f;
    c=f=0;
    printf("This Is The Table Of Temprature!\n");
    while (f<=300)
    {
	c=(5.0/9.0)*(f-32.0);
	printf("%d\t%d\n",f,c);
	f=f+20;
    }
}

	