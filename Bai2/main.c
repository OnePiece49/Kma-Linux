#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
//#include <sys/sysmacros.h>
int main()
{
	int fd;
	struct stat sb;
	fd = open("filesystem.txt", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("Open file failed\n");
	}
	stat("filesystem.txt", &sb);
	printf("File type:                ");

           switch (sb.st_mode & S_IFMT){  //0xXXXX and 0xF000  --> Ép 12 bit cuối là 0 --> Nghĩa là st_mode chả về 1 số 2 byte có 12 bít cuối #0
           case S_IFBLK:  printf("block device\n");            break;  //0x3000
           case S_IFCHR:  printf("character device\n");        break;  //0x2000
           case S_IFDIR:  printf("directory\n");               break;   //0x4000
           case S_IFIFO:  printf("FIFO/pipe\n");               break;   //0x1000
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;    //0x8000
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
	printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);
	printf("File size:                %jd bytes\n", (intmax_t) sb.st_size);
	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));

}
