/* ex 5-3, p107 */

#include <stdio.h>

void strcpy(char *s, char *t)
{
  while(*s++ = *t++);
}

void strcat(char *s, char *t)
{
  while(*s)
  {
    ++s;
  }
  strcpy(s, t);
}

int main(void)
{
  char testbuff[128];

  char *test[] =
  {
    "",
    "1",
    "12",
    "123",
    "1234"
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t thistest;
  size_t inner;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    for(inner = 0; inner < numtests; inner++)
    {
      strcpy(testbuff, test[thistest]);
      strcat(testbuff, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
    }
  }

  return 0;
}




Give nineteen programmers a spec, and you'll get at least twenty completely different programs. As a tiny example of this, here's a totally different solution, by Bryan Williams. 


/*

  Exercise 5-3. Write a pointer version of the function strcat that we showed in 
                Chapter 2: strcat(s,t) copies the string t to the end of s.

  implementation from chapter 2:

/ * strcat:  concatenate t to end of s; s must be big enough * /
void strcat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')  / * find end of s * /
    i++;
  while ((s[i++] = t[j++]) != '\0')  / * copy t * /
    ;
}


  Author : Bryan Williams 

*/


/* strcat:  concatenate t to end of s; s must be big enough; pointer version */
void strcat(char *s, char *t)
{
  /* run through the destination string until we point at the terminating '\0' */ 
  while('\0' != *s)
  {
    ++s;
  }

  /* now copy until we run out of string to copy */
  while('\0' != (*s = *t))
  {
    ++s;
    ++t;
  }

}

#define DRIVER         6

#if DRIVER
#include <stdio.h>

int main(void)
{
  char S1[8192] = "String One";
  char S2[8192] = "String Two";


  printf("String one is (%s)\n", S1);
  printf("String two is (%s)\n", S2);
 
  strcat(S1, S2);
  printf("The combined string is (%s)\n", S1);

  return 0;
}

#endif

