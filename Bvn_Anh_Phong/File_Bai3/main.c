#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

void clear_buff()
{
    while (getchar() != '\n');
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("it's not enough information\n");
        return 1;
    }
    
    char buff_read[100] = {0};
    char buff_write[100] = {0};
    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    int byte_read = atoi(argv[2]);

    if (fd == -1) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    if (byte_read < 0) {
        printf("Byte Read = %d < 0, failed \n", byte_read);
        return 1;
    }

    if (strcmp(argv[3], "r")  == 0 ) {
        printf("Mode : Read %d bytes from file %s\n", byte_read, argv[1]);
        read(fd, buff_read, byte_read);
        printf("Data read : %s\n", buff_read);
    } else if (strcmp(argv[3], "w")  == 0) {
        printf("Mode : Write %d bytes into file %s\n", byte_read, argv[1]);
        if (argc > 5) {
            write(fd, argv[4], byte_read);
            printf("Data write : %s\n", argv[4]);
        }
        if (argc < 5) {
            printf("Enter data to write into file %s : ", argv[1]);
            fgets(buff_write, byte_read, stdin);
            write(fd, buff_write, byte_read);
        }         
    } else {
        printf("No Mode to excute\n");
        return 1;
    }

    return 0;
}