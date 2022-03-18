#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define  NAMEFILE "hello_ae_wibu.txt"
int main()
{
	int fd = open(NAMEFILE, O_RDWR | O_CREAT | O_APPEND);
	char *str = "Huy ngu";
    //  lseek(fd, 4, SEEK_SET);
    char buff[50] = {0};
    read(fd, buff, 50);
    printf("Data read fom FILE : %s\n", buff);
	write(fd, str, strlen(str));
	close(fd);
	return 0;
}
