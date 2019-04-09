#include <stdio.h>


int power(int m, int n); /* function prototype */

/* test power function */
int main()
{
        int i;
        for (i = 0; i < 10; ++i)
                printf( "%d %d %d\n", i, power(2,i), power(-3,i));
        return 0;
}


/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
        int p;
        
        for (p = 1; n > 0; --n)
                p = p * base;
        return p;
}