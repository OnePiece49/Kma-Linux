#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT_NUMBER 10001
#define BUF_SIZE 10
char buf[200] = {0};
char buff_temp[200] = {0};
int i = 1;
char dataSend[200] = "Hello ban nho";
int main()
{
    int numb_read = 0, opt, fd;
    struct sockaddr_in svaddr = {0};
    int fddata, j;
    struct sockaddr_in claddr = {0};

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("cannot intiatize socket ");
        return 1;
    }
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        perror("setsockopt()"); 

    svaddr.sin_family = AF_INET;
    svaddr.sin_addr.s_addr = INADDR_ANY; 
    svaddr.sin_port = htons(PORT_NUMBER);

    if (bind(fd, (struct sockaddr *)&svaddr, sizeof(struct sockaddr_in) ) == -1) {
        printf("cannot bind socket ");
        return 1;
    }

    if( listen(fd, 9) == -1) {
        printf("lisen failed ");
        return 1;
    }else {
            printf("lisen OK\n");
    } 

    socklen_t len = sizeof(claddr);
    // if ((fddata = accept(fd, (struct sockaddr *)&claddr, &len))  == -1) {
    //    printf("server not accept");
    //    return 1;
    // }else {
    //    printf("accept connect %d\n", i++);
    // }
	
    while(1)
    {
        printf("\nStart Listening..... \n");
        fflush(stdin);
        if ((fddata = accept(fd, (struct sockaddr *)&claddr, &len))  == -1) {
            printf("server not accept");
            return 1;
        }else {
            printf("accept connect lan %d\n", i++);
            while(1){
                numb_read = read(fddata, buff_temp, 200);
                if (numb_read > 0) {
                    printf("Starting send message to client: hello ban nho\n");
                    if( write(fddata, dataSend, sizeof(dataSend)) > 0 ) printf("send data success\n");
                    break;
                }
            }
            printf("Header receive : %s", buff_temp);
        }
    }
	// while(1)
	// {
    //     numb_read = read(fddata, buff_temp, 200);
    //     if (numb_read > 0) {
    //         printf("Header receive : %s", buff_temp);
    //         if(write(fddata, dataSend, 200) > 0) printf("\nsend data success\n");
    //         //break;
    //     }
	// }

    // printf("Header receive : %s", buff_temp);
    printf("server is closed");
    close(fd);
}
