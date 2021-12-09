#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int rv, status;
    int child = fork();
    if(child >= 0){
        if(child == 0){
            printf("Pid tien trinh con %d\n", getpid());
	
	    exit(3);
	    sleep(3);
        }
        else{
            rv = waitpid(child, &status, NULL);
            if(rv == -1){
                printf("wait failed");
            }
            printf("Tien trinh cha %d\n",getpid());
            if(WIFEXITED(status)){
                printf("the child terminated normally");
            }
            if(WIFSIGNALED(status)){
                printf("the child process was terminated by a signal.");
            }
        }
    }
    else{
        printf("failed");
    }
    
}
