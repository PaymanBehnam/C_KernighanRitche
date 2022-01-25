#include <stdio.h>
float far_cel(float f);
{
    c=(5.0/9.0)*(f-32);
    return c;
}
main()
{
    float fahr,celsius;
    fahr=0;
    while(fahr<=300)
    {
	celsius=far_cel(fahr);
	printf("%3d\t%3.2f,",fahr,celsius);
	fahr=fahr+20;
    }
}
