#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 1234
int main()
{
    int shmid = shmget(KEY, 1024, 0666 | IPC_CREAT );
    char* shmaddr = (char *)shmat(shmid, (void *)0, 0);
    //printf("Data from Share Memory: %s", shmaddr);
    for (int i = 0; i < 200; i++ ) {
        printf("%c", shmaddr[i]);
    }
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
