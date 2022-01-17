#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(){

//printf("GRANDPARENT of all : %d \n",getppid());

int pid,A_pid, B_pid,pid2,C_pid,pid3,pid4;

printf("Immediately before the fork. Only one process at this point.\n");
fflush(stdout);

pid  = fork();

printf("Immediately after the fork. This statement should print twice.\n");
fflush(stdout);

// To create Nodes A and B
if (pid >0 )  //  A node

{
    wait(NULL);  
    A_pid= getpid();
    printf("I'm the parent. My pid is %d. My child's pid is %d.\n",getpid(),pid);
    fflush(stdout);
}

else if (pid ==0)  // B node
{  
    B_pid= getpid();
    printf("I'm the child. My pid is %d. My parent's pid is %d.\n",getpid(),getppid());
    fflush(stdout);

}
else{
    printf("CANT FORK ! \n");
    fflush(stdout);
}
}