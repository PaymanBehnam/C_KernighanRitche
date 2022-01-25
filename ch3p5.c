#include <stdlib.h>
#include <stdio.h>
    
void itob(int n, char s[], int b);
void reverse(char s[]);
int strlen(char *);

int main(void) 
{
    char string[10];
    int i;
    
    for ( i = 2; i <= 20; ++i ) 
    {
        itob(255, string, i);
        printf("Decimal 255 in base %-2d : %s\n", i, string);
    }
    return 0;
}

void itob(int n, char s[], int b) 
{
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, sign;
    if ( b < 2 || b > 36 ) 
        printf("Cannot support base %d\n", b);
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do 
    {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) 
{
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) 
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
