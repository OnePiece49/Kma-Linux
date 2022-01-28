#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2];
    char buff[40] = {0};
    int a = strlen("Hello ae wibu1");
    if (pipe(pipefd) == -1) {
        printf("Tao pipe loi");
        exit(EXIT_FAILURE);
    }

    write(pipefd[1], "Hello ae wibu1", strlen("Hello ae wibu1"));
    //printf("%d\n", a);
    write(pipefd[1], "Hello ae wibu2", strlen("Hello ae wibu2"));
    read(pipefd[0], buff, 40);
    printf("Data pipe : %s\n", buff);
    printf("CHILD: EXITING!");
    exit(EXIT_SUCCESS);
}
