#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define  NAMEFILE "hello_ae_wibu.txt"
int main()
{

    int fd1 = open(NAMEFILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int fd3 = open(NAMEFILE, O_RDWR);

    write(fd1, "vcl5678", 7);
    write(fd3, "world", 5);
    lseek(fd3, 0, SEEK_SET);
    write(fd1, "HELLO", 6);
    write(fd3, "Gidday", 6);
	close(fd3);
    close(fd1);
	return 0;
}
