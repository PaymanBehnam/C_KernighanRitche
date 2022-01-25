#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void expand(char * s1, char * s2);
char line[MAXLINE];

int read(char s[],int lim)
{
    int c,i;
    putchar('>');
    putchar('>');
    putchar('>');
    for(i=0;i<lim && (c=getchar())!=EOF && c!='\n';++i)
	s[i]=c;
    if(c=='\n')
	s[i++]='\n';
    s[i]='\0';
    return i;
}

int main(void) 
{
    char result[100];
    while(read(line,MAXLINE))
    {
	expand(result,line);
	printf("expanded : %s\n", result);
    }
    return 0;
}

void expand(char * s1, char * s2) {
    static char upper_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char lower_alph[27] = "abcdefghijklmnopqrstuvwxyz";
    static char digits[11]     = "0123456789";
    char * start, * end, * p;
    int i = 0;
    int j = 0;
    while ( s2[i] ) 
    {
        switch( s2[i] ) 
	{
        case '-':
            if ( i == 0 || s2[i+1] == '\0' ) 
	    {    
                s1[j++] = '-';
                ++i;
                break;
            }
            else 
	    {
        	if ( (start = strchr(upper_alph, s2[i-1])) &&(end   = strchr(upper_alph, s2[i+1])) )
                    ;
                else if ( (start = strchr(lower_alph, s2[i-1])) && (end   = strchr(lower_alph, s2[i+1])) )
                    ;
                else if ( (start = strchr(digits, s2[i-1])) && (end   = strchr(digits, s2[i+1])) )
                    ;
                else 
		{    
                    printf("Type of  '%c' and '%c' should be same \n",s2[i-1], s2[i+1]);
                    s1[j++] = s2[i-1];
                    s1[j++] = s2[i++];
                    break;
                }
                p = start;
                while ( p != end ) 
		{
                    s1[j++] = *p;
                    if ( end > start )
                        ++p;
                    else
                        --p;
                }
                s1[j++] = *p;
                i += 2;
            }
            break;
        default:
            if ( s2[i+1] == '-' && s2[i+2] != '\0' ) 
                ++i;
            else 
                s1[j++] = s2[i++];
            break;
        }
    }
    s1[j] = s2[i];
}
