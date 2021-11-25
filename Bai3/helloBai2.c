#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	pid_t child;
	int fd = open("hello.txt", O_RDWR | O_CREAT);
	char *str = "Hello ae wibu";
	write(fd, str, strlen(str));
	close(fd);
	child = fork();
	if(child >= 0)
	{	
		if(child == 0)
		{
			int fd1 = open("hello.txt", O_RDWR);
			char str2[50];
			read(fd1, str2, sizeof(str2));
		    printf("%s\n", str2);	
		} 
	}
	else
		printf("faild\n");
	return 0;
}
