#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

pthread_t thread_ID1, thread_ID2;
void handle_SIGINT()
{
    printf("Blocked\n");
}

void block_signal(int Mysignal, sigset_t *newset, sigset_t *oldset, int first_addSignal)
{
    if(first_addSignal == 0 ) {
        sigemptyset(newset);
        sigemptyset(oldset);
    }
    sigaddset(newset, Mysignal);
    if (sigprocmask(SIG_SETMASK, newset, oldset) == 0) {
        if( sigismember(newset, Mysignal) ){
            printf("Signal-%d da bi block\n", Mysignal);
        }
    }
}

void check_block_signal(sigset_t *sigset)
{
    for (int i = 1; i < 23; i++) {
        if( sigismember(sigset,  i) ) {
            printf( "  signal-%d is pending\n", i);
        }
    }
}

/* Không hiểu sao sigpending() chạy không đúng */
void check_block_signal_ver2()
{
    sigset_t sigset;
    if( sigpending(&sigset) != 0 )
            perror( "sigpending() error\n" );    

    for (int i = 1; i < 23; i++) {
        if( sigismember(&sigset,  i) ) {
            printf( "  signal-%d is pending\n", i);
        }
    }
}

void *thread_handle1()
{
    static int i = 0;
    signal(10, handle_SIGINT);
    sigset_t *newset = malloc(sizeof(sigset_t));
    sigset_t *oldset = malloc(sizeof(sigset_t));
    block_signal(SIGINT, newset, oldset, 0);
    block_signal(SIGTERM, newset, oldset, 1);
    check_block_signal_ver2();
    while(1) {
        printf("I'm thread 1\n");
        i++;
        sleep(2);
        if(i == 3) {
            pthread_kill(thread_ID2, SIGINT);
        }
    }
}


void *thread_handle2()
{
    static int i = 0;
    sigset_t *newset = malloc(sizeof(sigset_t));
    sigset_t *oldset = malloc(sizeof(sigset_t));
    block_signal(SIGINT, newset, oldset, 0);
    check_block_signal(newset);
    while(1) {
        i++;
        printf("I'm thread 2\n");
        sleep(3);
        if(i == 3) {
            pthread_kill(thread_ID1, SIGTERM);
            pthread_kill(thread_ID2, SIGINT);
        }
    }
}


int main()
{
    //signal(SIGINT, handle_SIGINT);
    pthread_create(&thread_ID1, NULL, thread_handle1, NULL);
    pthread_create(&thread_ID2, NULL, thread_handle2, NULL);
    while(1)
    {
        printf("Hello ae wibu\n");
        sleep(2);
    }


}