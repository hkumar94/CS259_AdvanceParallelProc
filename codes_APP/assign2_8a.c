#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(){

    for (int i = 0 ; i<8;i++)
    {
        printf("Sleep #%d\n",i+1);
        sleep(1);
    }


printf("Program exiting\n");
}