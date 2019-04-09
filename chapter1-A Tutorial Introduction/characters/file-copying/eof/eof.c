#include <stdio.h>
/* copy input to output; 2nd version */
int main()
{
int c;
printf("End of file = %d: \n", EOF);
printf("Type anythong you want ...:");
while ((c = getchar()) != EOF)
putchar(c);
}
