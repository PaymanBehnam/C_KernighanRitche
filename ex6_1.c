#include <stdio.h>
main()
{
    int c,ns,others,i;
    ns=others=0;
    int digit[10];
    for(i=0;i<10;++i)
	digit[i]=0;
    
    while((c=getchar())!=EOF)
    {
	if (c>='0'&&c<='9')
	{
	    ++digit[c-'0'];
	    
	}
	if (c=='\t'||c=='\n'||c==' ')
	    ++ns;
	else
	    ++others;
    }	
    printf("digits=");
    for(i=0;i<10;++i)
	printf("%d",digit[i]);
    printf("\n");
    printf("white space=%d\n",ns );
    printf("others=%d\n",others);
}
	    	    	        