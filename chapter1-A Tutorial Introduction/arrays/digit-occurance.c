#include <stdio.h>

/* count digits, white space , others */
int main()
{
	int c, i, nwhite, nother;
	// Designated Initializer: int num[5]={ [0 . . . 4 ] = 3 };               // num = { 3, 3, 3, 3, 3}
	// Designated Initializer: int num[  ]={ [0 . . . 4 ] = 3 };               // num = { 3, 3, 3, 3, 3}
	int ndigit[10];
	
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if ( c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else ++nother;

	printf("digits = ");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space =  %d, other = %d\n", nwhite, nother);
}
