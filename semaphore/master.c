#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <wait.h>
#include "sem.h"


int main()
{
    int pid, status[2];
    pid =  fork();
    srand(pid);
    if(pid < 0)
    {
        perror("fork"); exit(1);
    }
    else if(pid)
    {
        if (execl("./one", "1", (char*)NULL) == -1) {
            perror("execl p1");
            return -1;
        }
    }
    else
    {
	int pid2;
    	pid2 =  fork();
	srand(pid2);
	if(pid2 < 0)
    	{
        	perror("fork"); exit(1);
    	}
    	else if(pid2)
    	{
        	if (execl("./two", "2", (char*)NULL) == -1) {
            		perror("execl p2");
            		return -1;
        	}
    	}
    	else{
		waitpid(pid2, &status[1], 0);
		status[1] = WEXITSTATUS(status[1]);

		waitpid(pid, &status[0], 0);
		status[0] = WEXITSTATUS(status[0]);
		return 0;
    	}
    }
}
