#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc,  char * argv[]){
    //printf("origin : %d \n" );
    int id ;
    //printf("my PID is : %d and PARENT ID is : %d \n" , id, getpid());
    id = fork();
    
    if (id > 0){
        printf("my new parent PID is : %d and PARENT ID is : %d \n" , id, getpid());
        }
    else {
        printf("CHILD  PID is : %d and PARENT ID is : %d \n" , id, getpid());}


    // int id_2 = fork();
    // printf("Number - PID_2 is : %d \n" , id_2);
    return 0;
}