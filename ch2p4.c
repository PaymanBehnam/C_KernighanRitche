#include <stdio.h>
int squeeze(char s1[],char s2[])
{
    int i,j,e=0,flag=0;
    for(i=0;s1[i]!='\0';++i)
    {
	for(j=0;s2[j]!='\0';j++)
	{	
	    if(s1[i]==s2[j])
	    {
		flag=1;
		break;
	    }
	}
	if(flag==0)
	    s1[e++]=s1[i];
	flag=0;
    }
    s1[e]='\0';
    return e--;
}
main()
{
    int a;
    char s[]="asdfg";
    a=squeeze(s,"sd");
    printf("%s\n\t%d",s,a);
}
