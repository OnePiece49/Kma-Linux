#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>

int main()
{
    int fd[2], n=0, i;
    pipe(fd); 
    if (fork() == 0) { /* Child process */
        close(1); 
        dup(fd[1]); /* Redirect the stdout of this process to the pipe. */
        close(fd[0]);
        for (i=0; i < 10; i++) { 
            printf("%d\n",n);
            n++;  //Luu gia tri cua n vao trong Pipe
        }
    } else { /* Parent process */
        close(0) ;
        dup(fd[0]) ; /* Redirect the stdin of this process to the pipe */
        close(fd[1]);
        for (i=0; i < 10; i++) { 
            scanf("%d",&n);         //Lay gia tri tu trong Pipe va luu vao n
            printf("n = %d\n",n);   //In ra man hinh
            sleep(1);
        }
    } 
}