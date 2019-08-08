#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>

#include "sem.h"


int 
main(){
	int id = semget(KEY, 1, 0666 | IPC_CREAT);
    	if(id < 0)
    	{
        	perror("semget"); exit(11);
    	}
    	union semun u;
    	u.val = 1;
   	if(semctl(id, 0, SETVAL, u) < 0)
    	{
        	perror("semctl"); exit(12);
    	}
	
	char *s = "abcdefgh";
        int l = strlen(s);
        for(int i = 0; i < l; ++i)
        {
            if(semop(id, &p, 1) < 0)
            {
                perror("semop p"); exit(13);
            }
            putchar(s[i]);
            fflush(stdout);
            sleep(rand() % 2);
            putchar(s[i]);
            fflush(stdout);
            if(semop(id, &v, 1) < 0)
            {
                perror("semop p"); exit(14);
            }

            sleep(rand() % 2);
        }
	return 0;

}
