#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t thread_ID1, thread_ID2;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *thread_handle1()
{
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", ++count);
        sleep(1);
    }
    if( pthread_mutex_unlock(&lock) == 0) {
        printf("unlock successfully\n");
    }
    pthread_cond_signal(&cond);
    pthread_exit(NULL); 
}

void *thread_handle2()
{
    
}

int main()
{
    int count = 0;
    pthread_create(&thread_ID1, NULL, &thread_handle1, NULL);
    //Khi xoa sleep
    pthread_mutex_lock(&lock);
    printf("Hello ae wibu\n");
    while(1){
        pthread_cond_wait(&cond, &lock);
        if (count < 10) {
            printf("Xong 5 bi");
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    pthread_join(thread_ID1, NULL);
    return 0;
}