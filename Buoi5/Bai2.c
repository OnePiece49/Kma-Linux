#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

void handle_SIGINT()
{
    printf("Hello ae wibu");
}


int main()
{
    signal(SIGINT, handle_SIGINT);

    sigset_t newset, oldset;
    sigemptyset(&newset);
    sigemptyset(&oldset);
    sigaddset(&newset, SIGINT);

    if( sigprocmask(SIG_SETMASK, &newset, &oldset) == 0 ){
        sigprocmask(SIG_SETMASK, NULL, &oldset);
        if( sigismember(&oldset, SIGINT) ){
            printf("SIGINT da bi block");
        }
    }
    while(1)
    {
        printf("hello\n");
        sleep(2);
    }


}