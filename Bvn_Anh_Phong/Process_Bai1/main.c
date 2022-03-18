#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

void func()
{
    wait(NULL);
}

int main()
{
    pid_t child_pid = fork();
    
    if(child_pid == 0) {
        printf("I/m Process child %d\n", getpid());
    } 
    else if(child_pid > 0) {
        printf("I'm process parent %d\n", getppid());
        signal(SIGCHLD, func);
        while (1)
        {
            printf("I'm parent\n");
            sleep(2);
        }
    } 
    else {
        printf("failed to make fork\n");
        return 1;
    }
}