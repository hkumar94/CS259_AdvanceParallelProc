#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <unistd.h>





int main(){

//printf("GRANDPARENT of all : %d \n",getppid());

int pid,A_pid, B_pid,pid2,C_pid,pid3,pid4;

pid  = fork();



if (pid >0 )  

{
      
    
    printf("Parent starting wait \n");
    fflush(stdout);
    //nt t= 5;
    //wait(&t);
    printf("Parent finished wait \n");
    fflush(stdout);
    

}

else if (pid ==0)  
{  
    printf("Child going to sleep \n");
    fflush(stdout);
    sleep(5);
    printf("Child finished sleeping \n");
    fflush(stdout);
}

else{
    printf("CANT FORK ! \n");
    //fflush(stdout);
}
}