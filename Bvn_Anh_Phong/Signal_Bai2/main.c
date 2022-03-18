#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define NAME_FILE "dup.txt"
int main()
{
    char str[20] = {0};
    int fd = open(NAME_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    printf("fd = %d\n", fd);
    //close(0);
    int fd_coppy = dup2(fd, 0); //Tai sao ko nhap duoc data ?? Chua biet, sau hoi a phong
    printf("Nhap data : ");
    scanf("%s", str);
    printf("fd_coppy = %d \n", fd_coppy);
    printf("fd = %d\n", fd);
    write(fd, "dcmm dup\n", 9);
    write(fd_coppy, "hello dup\n", 9);
}

