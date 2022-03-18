#include <stdio.h>
#include <string.h>

// typedef struct {
//     char name[50];
//     int value;
// }share_mmr;
// char buff[50];
// int main()
// {
//     share_mmr Huy;

//     fgets(&Huy.name, 50, stdin);
//     scanf("%d", &Huy.value);
//     char string[20];
//     itoa(Huy.value,string,10);
//     strcpy(buff, &Huy.name);

//     strcpy(buff+ strlen(&Huy.name) - 1, string);

//     printf("%s", buff);
// }

void sua_ten(char *str, const char *name)
{
    char newname[30] = {0};
    int leng_newname = 0;
    char str_cpy[200] = {0};
    int length_str_after_hai_cham = 0;
    char *first = strstr(str, name);
    char *first_hai_cham = strstr(first, ":");
    if(strlen(name) == (first_hai_cham - first)) {
        length_str_after_hai_cham = strlen(first_hai_cham);
        strcpy(str_cpy, first_hai_cham);
        printf("Nhap ten moi: ");
        fgets(newname, 30, stdin);
        for(int i = 0; i < strlen(newname); i++) {
            if(newname[i] == '\n') {
                newname[i] = '\0';
            }
        }
        strcpy(first, newname);
        strcat(str, str_cpy);
        printf("Data after repair: %s\n", str);
    } 
    else {
        printf("No name belong to str\n");
    }
}

void xoa_name(char *str, const char *name)
{
    char str_cpy[200] = {0};
    char *first = strstr(str, name);
    if(first != NULL) {
        char *first_dau_phay = strstr(first, ",");
        char *first_hai_cham = strstr(first, ":");
        if(strlen(name) == (first_hai_cham - first)) {
            strcpy(str_cpy, first_dau_phay + 1);
            for(int i = 0; i < (first_dau_phay - first); i++) {
                first[i] = '\0';
            }
            strcat(str, str_cpy);
            printf("Data after delete : %s\n", str);
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
    char str_cpy[200] = {0};
    char *value_fake;
    char *value_real;
    char *first = strstr(str, name);
    if(first != NULL) {
        char *first_hai_cham = strstr(first, ":");
        char *first_dau_phay = strstr(first, ",");
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
    sua_ten(str, "huy");
    xoa_name(str, "huy ngu");
    truy_xuat_value(str, "vietdz ");
}