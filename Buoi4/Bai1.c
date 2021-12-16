#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

pthread_t thread_ID1, thread_ID2, thread_ID3;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int fd2, fd3;
char test = '1';
char PressAtocontinue1 = '\n';
int count = 0;
typedef struct 
{
    char name[50];
    char date[50];
    char town[50];
}inf_Sv;

inf_Sv SV;
void *thread_handle1()
{
    pthread_mutex_lock(&lock);
    printf("\nNhap ten Sv : ");
    fflush(stdin);
    scanf("%s", SV.name);
    fflush(stdin);
    printf("Nhap ngay sinh sinh vien: ");
    scanf("%s",SV.date);
    fflush(stdin);
    printf("Nhap que huong sinh vien: ");
    scanf("%s",SV.town);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

void *thread_handle2()
{
    pthread_join(thread_ID1, NULL);
    fd2 = open("thongtin.txt", O_RDWR | O_CREAT);
    lseek(fd2, 1, SEEK_END);
    write(fd2, &PressAtocontinue1, sizeof(PressAtocontinue1));
    write(fd2, SV.name, strlen(SV.name));
    write(fd2, SV.date, strlen(SV.date));
    write(fd2, SV.town, strlen(SV.town));
    // if(count != 0){
    //     lseek(fd2, 0, SEEK_SET);
    //     write(fd2, &PressAtocontinue1, 1);
    // 
    close(fd2);
    pthread_exit(NULL);
}

// void *thread_handle3()
// {
//     pthread_join(thread_ID2, NULL);
//     fd3 = open("thongtin.txt", O_RDWR | O_CREAT);
//     char buff[1000];
//     lseek(fd3, 1, SEEK_SET);
//     read( fd3, &buff, (strlen(SV.date) + strlen(SV.name) + strlen(SV.town) + 1 ) );
//     printf("thong tin trong file la: ");
//     printf("%s", buff);
//     // lseek(fd, 0, SEEK_SET);
//     // write(fd, &PressAtocontinue1, 1);
//     // write(fd, &test, 1);
//     close(fd3);
//     pthread_cond_signal(&cond);
//     pthread_exit(NULL);
// }


void *thread_handle3()
{
    pthread_join(thread_ID2, NULL);
    printf("thong tin trong file la: ");
    printf("%s%s%s", SV.name, SV.date, SV.town);
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}

int main()
{
    pthread_create(&thread_ID1, NULL, thread_handle1, NULL);
    pthread_create(&thread_ID2, NULL, thread_handle2, NULL);
    pthread_create(&thread_ID3, NULL, thread_handle3, NULL);
    pthread_mutex_lock(&lock);
    while(1){
        pthread_cond_wait(&cond, &lock);
        pthread_create(&thread_ID1, NULL, thread_handle1, NULL);
        sleep(1);
        pthread_create(&thread_ID2, NULL, thread_handle2, NULL);
        sleep(1);
        pthread_create(&thread_ID3, NULL, thread_handle3, NULL);
    } 
    pthread_mutex_unlock(&lock);
    return 0;   
}