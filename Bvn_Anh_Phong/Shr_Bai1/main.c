#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 1234
int long_segement = 0;
typedef struct {
    char name[50];
    int value;
}share_mmr;

void newData(share_mmr *data) {
    printf("\nEnter new name: ");
    fgets(&data->name, 50, stdin);
    printf("Enter new value: ");
    scanf("%d", &data->value);
    getchar();
}

void AddName(char *shmaddr) {
    char dau_hai_cham[2] = ":"; 
    char dau_phay[2] = ",";
    char string[20] = {0};
    share_mmr data;
    newData(&data);
    sprintf(string, "%d", data.value);
    strcpy(shmaddr + long_segement, &data.name); //name
    strcpy(shmaddr + long_segement + strlen(&data.name) - 1, dau_hai_cham); // :
    strcpy(shmaddr + long_segement + strlen(&data.name) , string);          // value
    strcpy(shmaddr + long_segement + strlen(&data.name) + strlen(string), dau_phay);  // ,
    long_segement = long_segement + strlen(&data.name) + strlen(string) + 1;
    //  printf("Data shareMemory with for: ");
    // for(int i = 0; i < 100; i++) {
    //     printf("%c", shmaddr[i]);
    // }
    // printf("\n");
    printf("Data shareMemory with printf: %s va do dai %d\n", shmaddr, long_segement);
}

void sua_ten( char *shmaddr, const char *name)
{
    char newname[30] = {0};
    int leng_newname = 0;
    char str_cpy[1024] = {0};
    char *first_hai_cham;
    int length_str_after_hai_cham = 0;
    char *first = strstr(shmaddr, name);
    if(first != NULL) {
        first_hai_cham = strstr(first, ":");
        if(strlen(name) == (first_hai_cham - first)) {
            length_str_after_hai_cham = strlen(first_hai_cham);
            strcpy(str_cpy, first_hai_cham);
            //printf("Data sau dau hai cham : %s\n", first_hai_cham);
            printf("\nNhap ten moi: ");
            fgets(newname, 30, stdin);
            for(int i = 0; i < strlen(newname); i++) {
                if(newname[i] == '\n') {
                    newname[i] = '\0';
                }
            }
            strcpy(first, newname);
            strcat(shmaddr, str_cpy);
            printf("Data after repair: ");
                for(int i = 0; i < 100; i++) {
                printf("%c", shmaddr[i]);
            }
        } 
    }
    else {
        printf("No name belong to str\n");
    }
}

void xoa_name(char *shmaddr, const char *name)
{
    char data[1000] = {0};
    char *first_dau_phay;
    char *first_hai_cham;
    
    char str_cpy[1024] = {0};
    strcpy(data, shmaddr);
    printf("%s\n", data);
    memset(shmaddr, 0, strlen(shmaddr));
    char *first = strstr(data, name);
    if(first != NULL) {
        first_dau_phay = strstr(first, ",");
        first_hai_cham = strstr(first, ":");
        if(strlen(name) == (first_hai_cham - first)) {
            strcpy(str_cpy, first_dau_phay + 1);
            for(int i = 0; i < (first_dau_phay - first + 1); i++) {
                first[i] = '\0';
            }
            strcat(data, str_cpy);
            printf("\nData after delete : %s\n", data);
            strcpy(shmaddr, data);
        }
        else {
            printf("No name belong to str\n");
        }
    }
    else {
        printf("No name\n");
    }

}

void truy_xuat_value(char *str, const char *name)
{
    char str_cpy[1024] = {0};
    char *value_fake;
    char *value_real;
    char *first_hai_cham;
    char *first_dau_phay;
    char *first = strstr(str, name);
    if(first != NULL) {
        first_hai_cham = strstr(first, ":");
        first_dau_phay = strstr(first, ",");
        if(strlen(name) == (first_hai_cham - first)) {
            value_fake = strtok(first, ",");
            value_real = strtok(str, ":");
            printf("value is: %s", value_fake + strlen(name) + 1);
        }
        else {
            printf("No name belong to str\n");
        }
    }
    else {
        printf("No name\n");
    }
}


int main()
{
    char str[100] = "vietdz :2000,long:100,linh:300,huy:23,";
    int shmid = shmget(KEY, 2048, 0666 | IPC_CREAT);
    char* shmaddr = (char *)shmat(shmid, (void *)0, 0);
    AddName(shmaddr);
    AddName(shmaddr);
    AddName(shmaddr);
    AddName(shmaddr);
    sua_ten(shmaddr, "vietdz ");
    xoa_name(shmaddr, "long");
    truy_xuat_value(shmaddr, "ling");
}