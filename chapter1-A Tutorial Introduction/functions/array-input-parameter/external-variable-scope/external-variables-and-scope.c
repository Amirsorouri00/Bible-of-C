#include<stdio.h>

#define MAXLINE     1000    /* maximum input line size */

/* 
1.common practice is to place definitions of all external variables at
the beginning of the source file, and then omit all extern declarations.
--------------------------------------------------------------------------------
2.If the program is in several source files, and a variable is defined in filel
and used in fUe2 and file3, then extern declarations are needed in file2 and
file3 to connect the occurrences of the variable. 
--------------------------------------------------------------------------------
3.The usual practice is to collect
extern declarations of variables and functions in a separate file, historically
called a header, that is included by #include at the front of each source file.
The suffix • h is conventional for header names.
*/
int max;                    /* maximum length seen so far */
char line[MAXLINE];         /* current input line */
char longest[MAXLINE];      /*  longest line saved so far */

int my_getline(void); /* void must be used for an explicitly empty list */
void copy(void);


/* print longest input line; specialized version */
int main(){
    int len;                    /* private or local, or automatic variable */
    extern int max;             /* tutorial for extern: https://www.tutorialspoint.com/extern-keyword-in-c */
    extern char longest[];

    max = 0;
    while ((len = my_getline()) > 0){
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline: specialized version */
int my_getline(void){
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */
void copy(void){
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0'){
        ++i;
    }
}