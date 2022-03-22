#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void handle_SIGINT()
{
    printf("Blocked\n");
}

void block_signal(int Mysignal, sigset_t *newset, sigset_t *oldset, int first_addSignal)
{
    if (first_addSignal == 0) {
        sigemptyset(newset);
        sigemptyset(oldset);
    }
    sigaddset(newset, Mysignal);

    if (sigprocmask(SIG_SETMASK, newset, oldset) == 0) {
        if (sigismember(newset, Mysignal)) {
            printf("Signal-%d da bi block\n", Mysignal);
        }
    }
}

void check_block_signal(sigset_t *sigset)
{
    for (int i = 1; i < 23; i++) {
        if (sigismember(sigset, i)) {
            printf( "  signal-%d is pending\n", i);
        }
    }
}

int main()
{
    signal(SIGINT, handle_SIGINT);
    sigset_t newset, oldset;
    block_signal(SIGINT, &newset, &oldset, 0);
    check_block_signal(&newset);
    while (1) {
        printf("Hello ae wibu\n");
        sleep(3);
    }
}
