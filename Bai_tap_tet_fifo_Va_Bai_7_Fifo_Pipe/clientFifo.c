#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <unistd.h>

#define PATH_FIFO_CLIENT "/home/vietdz/working_space/BTL_SOCKET_FIFO/"
#define Key "WibuGod"
char dataSend[200] = {0};
char dataRead[200] = {0};
int numb_read = 0;
int main(int argc, char **argv)
{
    if (argc < 3 ){
        printf("Not enough information to connect Server \n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_in addr_server = {0};
    int port_number = atoi(argv[2]);
    char name_fifo[100] = {0};
    char path_fifo[100] = "./"; 
    char header[200] = {0};
    char service[20];

    // if ((sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0)) {
    //     printf("Could not creat socket client\n");
    //     return 1;
    // }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(port_number);
    if (inet_pton(AF_INET, argv[1], &addr_server.sin_addr.s_addr) == -1) {
        printf(" errorr inet_pton()");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&addr_server, sizeof(addr_server)) == -1)
        printf("errorr connect()");
    
    printf("Starting make header to Server\n");
    
    printf("Name of file FIFO: ");
    fflush(stdin);
    scanf("%s", name_fifo);
    strcat(path_fifo, name_fifo);
    printf("path fifo just has created : %s", path_fifo);
    mkfifo(path_fifo, 0666);

    printf("\nEnter Service client : ");
    fflush(stdin);
    scanf("%s", &service); 

    /* Header include 1,path_fifo 2,Key 3,Service */
    strcat(header, path_fifo);
    strcat(header, (const char *)&service);
    strcat(header, Key);
    printf("Header includes %s\n", header);
    write(sockfd, header, strlen(header));
    printf("Starting receive message to server through FIFO\n");
    // printf("Enter content to Server : ");
    // fflush(stdin);
    // scanf("%s", dataSend);
    // write(sockfd, dataSend, strlen(dataSend));
    while(1){
        //numb_read = read(sockfd, dataRead, 500);
        if(read(sockfd, dataRead, sizeof(dataRead)) > 0){
            printf("Recieve done\n");
            printf("Data receive from Server : %s\n", dataRead);
        }   
    }
}