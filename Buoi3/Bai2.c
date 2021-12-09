#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int fd = open("text.txt", O_RDWR | O_CREAT);
    int statusC1, statusB1, statusC, statusB;
    int  childB, childC, childB1, childC1;
    childB = fork();            
    if(childB >= 0){
        if(childB == 0){                                       
            childB1 = fork();                                                                       //Tien trinh con B'
            if(childB1 >= 0){
                if(childB1 == 0){
                    write(fd, "I'm superman B'\n", sizeof("I'm superman B'\n"));                    //B1--In tien trinh B' process
                }
                else{                                                                               //Tien trinh con B--main
                    sleep(1);
                    write(fd, "I'm superman B\n", sizeof("I'm superman B\n"));                      //B3--In tien trinh B process
                }
            } 
        }
        if(childB > 0){                                                                             //Tien trinh con main
            childC = fork();       
            if(childC >= 0){                                    
                if(childC == 0){                                                                    //Tien Trinh C                                         
                    childC1 = fork();   
                    if(childC1 == 0){                                                               //Tao ra tien trinh con C'
                        sleep(0.5);
                        write(fd, "I'm superman C'\n", sizeof("I'm superman C'\n"));                //B2--In ra tien trinh con C'
                    }
                }
                if(childC > 0){                                                                     //Tien trinh main
                    waitpid(childB, &statusB, NULL);                                                //Doi tien trinh con B ket thuc
                    sleep(1.5);
                    write(fd, "I'm superman A\n", sizeof("I'm superman A\n"));                      //B4--In ra tien trinh con A
                    write(fd, "I'm superman C\n", sizeof("I'm superman C\n"));                      //B5--In ra tien trinh con C
                }
            }
        }    
    }
}

