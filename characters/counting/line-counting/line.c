#include <stdio.h>

/* count lines in input */
int main(){
	int c, n1;
	
	n1 = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++n1;

	printf("line number = %d\n", n1);
}
