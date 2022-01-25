#include <stdio.h>
main()
{
    int blank=0,tab=0,nl=0,c;
    while((c=getchar())!=EOF){
	if(c==' ')
	    ++blank;
	if(c=='\n')
	    ++nl;    
	if(c=='\t')
	    ++tab;
    }
    printf("blank=%i\ttab=%i\tnewline=%i\n",blank,tab,nl);
}    