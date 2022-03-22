#include <stdio.h>

int func(int a) 
{
    return a++;
}

int main()
{
    int a = 5;
    int arr[10] = {1, 3, 5, 9};
    for(int i = 0; i < 10; i++) {
        arr[i] = func(i);
    }
}