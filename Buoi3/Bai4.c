#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

pthread_t thread_ID1, thread_ID2;

typedef struct
{
    char name[30];
    char date[20];
    char number[20];
    char town[50];
}human;

static void *func(void *argv)
{
    pthread_t pid = pthread_self();
    human *data = (human *)argv;
    if( pthread_equal(pid, thread_ID1) ){
        printf("Hello I'm thread ID1\n");
    }
    else{
        printf("Hello I'm thread ID2\n");
        printf("%s\n",data->name);
    }

}

int main()
{
    human viet1, *viet;
    viet = &viet1;
    strcpy(viet->name, "Vietdz");
    strcpy(viet->date,"10/3/2000");
    strcpy(viet->number,"0962557063");
    strcpy(viet->town,"VanDinh");

    if( pthread_create(&thread_ID1, NULL, &func, NULL) ){
        printf("error thread_ID1");
        return -1;
    }
    
    if( pthread_create(&thread_ID2, NULL, &func, viet) ){
        printf("error thread_ID2");
        return -1;
    }

    sleep(5);
}
