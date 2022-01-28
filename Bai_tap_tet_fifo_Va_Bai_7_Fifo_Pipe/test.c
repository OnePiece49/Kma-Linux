#include <stdio.h>
#include <string.h>

//#define Key "WibuGod"
// int main()
// {
//     char name_fifo[100] = {0};
//     char header[200] = {0};
//     char path_fifo[100] = "/home/vietdz/working_space/BTL_SOCKET_FIFO/";
//     char Key[8] = "WibuGod";
//     char service[5];

//     printf("Starting make header to Server\n");
//     printf("Name of file FIFO : ");
//     scanf("%s", name_fifo);
//     strcat(path_fifo, name_fifo);
//     printf("%s", path_fifo);

//     printf("\nEnter Service client : ");
//     fflush(stdin);
//     scanf("%s", &service); 

//     strcat(header, path_fifo);
//     strcat(header, (const char *)&service);
//     strcat(header, Key);
//     //printf("Header includes %s%s%d\n", path_fifo, Key, service);
//     printf("Header includes %s\n", header);
// }


// void json(char *abc)
// {
//     char path_client[50] = {0};
//     char service[50] = {0};
//     char Key[50] = {0};
//     char * p;
//     p = strtok(abc, ":");
//     strcat(path_client, p);
//     p = strtok(NULL, ":");
//     strcat(service, p);
//     p = strtok(NULL, ":");
//     strcat(Key, p);
//     printf("%s %s %s", path_client,service, Key);
// }

// int main()
// {
//     char abc[100] = "viet:dz:vl";
//     json(abc);
// }

int main()
{
    char abc[100] = {0};
    int a = strlen(abc);
    if(a < 100){
        for(int i = a; i < 99; i++){
            abc[i] = '*';
        }
    }
    printf("%s", abc);
}