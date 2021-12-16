#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = open("test.txt", O_RDWR | O_CREAT);
    write(fd, "dcm1m thanglong \n", strlen("dcm1m thanglong"));
    lseek(fd, 5, SEEK_SET);
    write(fd, "abc xyz", strlen("abc xyz"));
    lseek(fd, 10, SEEK_SET);
    write(fd, "long ngu nhu boljhg", strlen("long ngu nhu boljhg"));
    close(fd);
    return 0;
}