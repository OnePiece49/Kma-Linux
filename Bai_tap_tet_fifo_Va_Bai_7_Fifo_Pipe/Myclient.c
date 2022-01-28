#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PATH_FIFO_SERVER "./serverfifo"
#define Key "WibuGod"
#define BYTE_NUMBER 100
int fd_server, fd_client;

void Send_data_to_Server(char header[200])
{
    int byte_send = 0;
    char data[100] = {0};
    printf("Data to server: ");
    fflush(stdin);
    scanf("%s", data);
    byte_send = (strlen(header) + strlen(data));
    if(byte_send < 99) {
        for(int i = strlen(data); i < (100 - strlen(header)); i++ ){
                data[i] = '*';
        }
        printf("data send %s %s", header, data);
        write(fd_server, header, strlen(header));
        write(fd_server, ":", strlen(":"));
        write(fd_server, data, strlen(data));
    }

}

void Receive_data_from_Server()
{
    char data[100] = {0};
    read(fd_client, data, 100);
    printf("\nData receive from server : %s\n", data);
}

int main()
{
    char ACK = NULL;
    char Dau_hai_cham[2] = ":";
    char header[200] = {0};
    char dataSend[200] = {0};
    char dataReceive[200] = {0};
    char name_fifo[100] = {0};
    char path_fifo[100] = "./"; 

    char service[20];

    printf("Name of file FIFO: ");
    fflush(stdin);
    scanf("%s", name_fifo);
    strcat(path_fifo, name_fifo);
    printf("path fifo just has created : %s", path_fifo);
    mkfifo(path_fifo, 0666);
    fd_server = open(PATH_FIFO_SERVER, O_RDWR);
    fd_client = open(path_fifo, O_RDWR);

    printf("\nEnter Service client : ");
    fflush(stdin);
    scanf("%s", &service); 

    /* Header include 1,path_fifo 2,Key 3,Service */
    strcat(header, path_fifo);
    strcat(header, Dau_hai_cham);
    strcat(header, service);
    strcat(header, Dau_hai_cham);
    strcat(header, Key);
    write(fd_server, header, strlen(header));
    printf("Header includes : %s\n", header);
    //sleep(1);
    if (read(fd_client, &ACK, 1) > 0){
        printf("Bit ACK = %c\n", ACK);
        if(ACK == '0') {
            printf("failed connect to server\n");
            execl("/bin/rm", "rm", "-r", "-f", path_fifo, NULL);
            return 1;
        }else{
            printf("Connect successfully\n");
            printf("Starting send message to server through FIFO....\n");
        }
    }
    while (1)
    {
        Send_data_to_Server(header);
        Receive_data_from_Server();
    }
    
    
}