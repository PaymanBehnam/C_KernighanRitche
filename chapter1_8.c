#include <stdio.h>
main()
{
    int c,ns,nt,nl;
    ns=nt=nl=0;
    while ((c=getchar())!=EOF)
    {
	if (c==' ')
	    ++ns;
	if (c=='\t')
	    ++nt;
	if (c=='\n')
    	    ++nl;
    }
    printf("The Total of space=%d\n",ns);
    printf("The Total of tab=%d\n",nt);
    printf("the total of newlinel=%d\n",nl);
}
