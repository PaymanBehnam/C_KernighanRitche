/*
 * Exercise 5-2 from The C Programming Language, 2nd edition, by Kernighan
 * and Ritchie.
 *
 * "Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value?"
 */

/*
 * Here's the getint function, from section 5.2:
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
        int c, sign;
        
        while (isspace(c = getch()))   /* skip white space */
                ;
        
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);  /* it is not a number */
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
                c = getch();
        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}

/*
 * The getch and ungetch functions, from section 4.3, are also required.
 */

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

/*
 * The getfloat function.
 *
 * Reads the next number from input, and puts it into *fp.  Returns EOF for
 * end of file, zero if the next input is not a number, and a positive
 * value of the input contains a valid number.
 *
 * Based heavily on the getint function from K&R2.
 */

#include <ctype.h>
#include <math.h>

int getfloat(float *fp)
{
        int ch;
        int sign;
        int fraction;
        int digits;

        while (isspace(ch = getch()))   /* skip white space */
                ;

        if (!isdigit(ch) && ch != EOF && ch != '+'
                        && ch != '-' && ch != '.') {
                ungetch(ch);
                return 0;
        }

        sign = (ch == '-') ? -1 : 1;
        if (ch == '+' || ch == '-') {
                ch = getch();
                if (!isdigit(ch) && ch != '.') {
                        if (ch == EOF) {
                                return EOF;
                        } else {
                                ungetch(ch);
                                return 0;
                        }
                }
        }

        *fp = 0;
        fraction = 0;
        digits = 0;
        for ( ; isdigit(ch) || ch == '.' ; ch = getch()) {
                if (ch == '.') {
                        fraction = 1;
                } else {
                        if (!fraction) {
                                *fp = 10 * *fp + (ch - '0');
                        } else {
                                *fp = *fp + ((ch - '0') / pow(10, fraction));
                                fraction++;
                        }
                        digits++;
                }
        }

        *fp *= sign;

        if (ch == EOF) {
                return EOF;
        } else {
                ungetch(ch);
                return (digits) ? ch : 0;
        }
}

/*
 * Test module.
 */

#include <stdio.h>

int main(void)
{
        int ret;

        do {
                float f;

                fputs("Enter a number: ", stdout);
                fflush(stdout);
                ret = getfloat(&f);
                if (ret > 0) {
                        printf("You entered: %f\n", f);
                }
        } while (ret > 0);

        if (ret == EOF) {
                puts("Stopped by EOF.");
        } else {
                puts("Stopped by bad input.");
        }
        
        return 0;
}





...and here is Greg's solution: 


/* Gregory Pietsch <gkp1@flash.net> Exercise 5-2 dated 2001-01-08 */

#include <ctype.h>
#include <limits.h>

/* also uses getch and ungetch from Section 4.3 */

/* number of significant digits in a double */
#define SIG_MAX 32

/* store double in d; return next character */
int getfloat(double *d)
{
    const char point = '.';     /* localeconv->decimal_point[0]; */
    int c;
    char buf[SIG_MAX], sign, sawsign, sawe, sawesign, esign;
    double x;
    static double fac[] = {0.0, 1.0e8, 1.0e16, 1.0e24, 1.0e32};
    double dpow;
    int ndigit, nsig, nzero, olead, opoint, n;
    char *pc;
    long lo[SIG_MAX / 8 + 1], lexp;
    long *pl;

    /* skip white space */
    while (isspace(c = getch()))
        ;
    if (sawsign = (c == '-' || c == '+')) {
        sign = c;
        c = getch();
    } else
        sign = '+';
    olead = -1;
    opoint = -1;
    ndigit = 0;
    nsig = 0;
    nzero = 0;
    while (c != EOF) {
        if (c == point) {
            if (0 <= opoint)
                break;  /* already seen point */
            else
                opoint = ndigit;
        } else if (c == '0') {
            /* saw a zero */
            nzero++;
            ndigit++;
        } else if (!isdigit(c))
            break;      /* found nondigit */
        else {
            /* got a nonzero digit */
            if (olead < 0)
                olead = nzero;
            else {
                /* deliver zeros */
                for ( ; 0 < nzero && nsig < SIG_MAX; --nzero)
                    buf[nsig++] = 0;
            }
            ++ndigit;
            /* deliver digit */
            if (nsig < SIG_MAX)
                buf[nsig++] = (c - '0');
        }
        c = getch();
    }
    if (ndigit == 0) {
        /* no digits? */
        *d = 0.0;
        if (c != EOF)
            ungetch(c);
        if (0 <= opoint) {
            /* saw point */
            ungetch(c = point);
        }
        if (sawsign) {
            /* saw sign */
            ungetch(c = sign);
        }
        return c;
    }
    /* skip trailing digits */
    for ( ; 0 < nsig && buf[nsig - 1] == 0; --nsig)
        ;
    /* compute significand */
    pc = buf;
    pl = &(lo[nsig >> 3]);
    for (*pl = 0, n = nsig; 0 < n; --n) {
        if ((n & 7) == 0)
            /* start new sum */
            *--pl = *pc++;
        else
            *pl = *pl * 10 + *pc++;
    }
    for (*d = (double)(lo[0]), n = 0; ++n <= (nsig >> 3); )
        if (lo[n] != 0)
           *d += fac[n] * (double)(lo[n]);
    /* fold in any explicit exponent */
    lexp = 0;
    if (c == 'e' || c == 'E') {
        /* we have an explicit exponent */
        sawe = c;
        c = getch();
        if (sawesign = (c == '+' || c == '-')) {
            esign = c;
            c = getch();
        } else
            esign = '+';
        if (!isdigit(c)) {
            /* ill-formed exponent */
            if (c != EOF)
                ungetch(c);
            if (sawesign)
                ungetch(c = esign);
            c = sawe;
        } else {
            /* get exponent */
            while (isdigit(c)) {
                /* get explicit exponent digits */
                if (lexp < 100000)
                    lexp = lexp * 10 + (c - '0');
                /* else overflow */
                c = getch();
            }
            if (esign == '-')
                lexp = -lexp;
        }
    }
    if (c != EOF)
        ungetch(c);
    if (opoint < 0)
        lexp += ndigit - nsig;
    else
        lexp += opoint - olead - nsig;
    /* this is where I pray I don't lose precision */
    esign = (lexp < 0) ? '-' : '+';
    /* if anyone has a better way of handling overflow, tell me */
    if (lexp < SHRT_MIN)
        lexp = SHRT_MIN;
    if (lexp > SHRT_MAX)
        lexp = SHRT_MAX;
    if (lexp < 0)
        lexp = -lexp;
    if (lexp != 0) {
        dpow = (esign == '-') ? 0.1 : 10.0;
        while (lexp != 0) {
            /* form 10.0 to the lexp power */
            if ((lexp & 1) != 0) /* lexp is positive */
                *d *= dpow;
            lexp >>= 1;
            dpow *= dpow;
        }
    }
    /* if there was a minus sign in front, negate *d */
    if (sign == '-')
        *d = -(*d);
    return c;
}

