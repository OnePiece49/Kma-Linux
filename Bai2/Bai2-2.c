#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

static char buffer[50]; // static buffer internal for asctime
char *my_asctime(char* a) { // asctime
    snprintf(buffer, 50, "%s", a); // asctime converts the input to some output
    return buffer; // and returns pointer to internal buffer
}

int main()
{
    int i;
    int fdA, fdB;
	struct stat sb;
	fdA = open("fileA.txt",  O_RDWR | O_CREAT );
	if(fdA == -1 )
	{
		printf("Open file failed\n");
	}
	stat("fileA.txt", &sb);
    int dem = 0;
    char first = '0';
    write(fdA, &first , 1);
    char* time_open = ctime(&sb.st_mtime);
    my_asctime(time_open);
    printf("%s\n",buffer);
	for(int i = 1; i < 1000000; i++)
	{
		dem++;
	}
    printf("%d\n",dem);
	int str[dem];
    char b[100];
	for (int i = 1; i < 1000000; i++)
	{
		sprintf(b, "%d", i);
		strcat((char *)str,(char *)b);
	}
    write(fdA, str , sizeof(str));
    char* time_done = ctime(&sb.st_mtime);
    my_asctime(time_done);
    printf("%s\n",buffer);
    close(fdA);
    return 0;
}

