#include <stdio.h>
main()
{
    long nc;
    nc=0;
    while (getchar()!=EOF )
	++nc;
    printf("\n");
    printf("The Total Number Of Characters=%d\n ",nc);
}