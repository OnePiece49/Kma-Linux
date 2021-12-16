#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
pthread_t th;
void* roll_dice() {
  
    sleep(1);
    printf("1");
       sleep(1);
    printf("2");
      sleep(1);
    printf("3");
      sleep(1);
    printf("4");
      sleep(1);
    printf("5");
        sleep(1);
    printf("6");
       sleep(1);
    printf("7");
      sleep(1);
    printf("8");
      sleep(1);
    printf("9");
      sleep(1);
    printf("10");

}


// void *thread_handle2()
// {
//   sleep(5);
//   pthread_exit(NULL);
// }

int main(int argc, char* argv[]) {
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    // if (pthread_create(&th, NULL, &thread_handle2, NULL) != 0) {
    //     return 1;
    // }
    sleep(15);
    //while(1);
    return 0;
}