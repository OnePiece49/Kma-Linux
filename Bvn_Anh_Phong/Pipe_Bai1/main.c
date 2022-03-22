#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

int main()
{
    /*pipe 1: parrent to child, pipe2: child to parrent */
    int pipefd1[2], pipefd2[2];
    int child_pid;
    char buff_fd1[100] = {0};
    char buff_fd2[100] = {0};
    
    if (pipe(pipefd1) == -1) {
        printf("failed pipe 1\n");
    }
    if (pipe(pipefd2) == -1) {
        printf("failed pipe 1\n");
    }

    child_pid = fork();
    if (child_pid == 0) {
        while (1) {
            memset(buff_fd1, 0, 100);
            memset(buff_fd2, 0, 100);
            close(pipefd1[0]);
            close(pipefd2[1]);
            printf("Enter data to send to child : ");
            fgets(buff_fd1, 100, stdin);
            for(int i = 0; i < strlen(buff_fd1); i++) {
                if(buff_fd1[i] == '\n') {
                    buff_fd1[i] = '\0';
                }
            }
            write(pipefd1[1], buff_fd1, strlen(buff_fd1));
            read(pipefd2[0], buff_fd2, 100);
            printf("Data receive from child : %s\n", buff_fd2);
        }
    } else if(child_pid > 0) {
        while (1) {
            memset(buff_fd1, 0, 100);
            memset(buff_fd2, 0, 100);
            close(pipefd1[1]);
            close(pipefd2[0]);
            read(pipefd1[0], buff_fd1, 100);    
            printf("  Data receive from parent : %s", buff_fd1);
            for(int i = 0; i < strlen(buff_fd1); i++) {
                buff_fd1[i] = toupper(buff_fd1[i]);
            }
            write(pipefd2[1], buff_fd1, strlen(buff_fd1));
        }
    } else {
        printf("failed to make fork()\n");
    }
}