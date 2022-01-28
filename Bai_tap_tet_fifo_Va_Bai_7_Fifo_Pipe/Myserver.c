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

char path_client[1000] = {0};
char service[1000] = {0};
int fd;

void Add_path_client(char* save_path_client, char *save_service)
{
    strcat(path_client, save_path_client);
    strcat(service, save_service);
}

void json_data(char *abc)
{
    int fd_client;
    char path_clien_temp[50] = {0};
    char service_temp[50] = {0};
    char Key_temp[50] = {0};
    char * p;
    
    p = strtok(abc, ":");
    strcat(path_clien_temp, p);
    fd_client = open(path_clien_temp, O_RDWR);
    p = strtok(NULL, ":");
    strcat(service, p);
    p = strtok(NULL, ":");
    strcat(Key_temp, p);
    // printf("%s %s %s", path_client,service, Key_temp);
    if (strcmp(Key_temp, Key) == 0) {
        Add_path_client(path_client, service_temp);
        write(fd_client, "1", 1);
    }else{
        write(fd_client, "0", 1);
    }
}

void Send_read_Data_Client_Server(char *dataReive)
{
    char data[200];
    int fd_client;
    char path_clien_temp[50] = {0};
    char * p, *check;
    char service_temp[50] = {0};
    char Key_temp[50] = {0};
    char data_real_receive[200];
    
    p = strtok(dataReive, ":");
    strcat(path_clien_temp, p);
    p = strtok(NULL, ":");
    strcat(service, p);
    p = strtok(NULL, ":");
    strcat(Key_temp, p);
    p = strtok(NULL, ":");
    strcat(data_real_receive, p);
    printf("Data recive from fifo %s : %s\n", path_clien_temp, data_real_receive);
    fd_client = open(path_clien_temp, O_RDWR);
    printf("Enter data to send to client %s : ", path_clien_temp);
    fflush(stdin);
    scanf("%s", data);
    write(fd_client, data, strlen(data));
}

int main()
{
    int numb_read = 0;
    char dataSend[200] = {0};
    char dataReceive[200] = {0};
    mkfifo(PATH_FIFO_SERVER, 0666);
    fd = open(PATH_FIFO_SERVER, O_RDWR);
    while(1){
        numb_read = read(fd, dataReceive, sizeof(dataReceive));
        if(numb_read > 90){
            numb_read = 0;
            Send_read_Data_Client_Server(dataReceive);
            memset(dataReceive, 0, sizeof(dataReceive));
        }
        if ((numb_read < 90) && (numb_read > 0)) {
            printf("Header of client : %s\n", dataReceive);
            numb_read = 0;
            json_data(dataReceive);
            memset(dataReceive, 0, sizeof(dataReceive));
        }
    }
}

// int main()
// {
//     char hello[4] = "cmm";
//     char cl[5] = "hiih";
//     Add_path_client(cl);
//     Add_path_client(hello);
//     printf("%s", path_client);
// }