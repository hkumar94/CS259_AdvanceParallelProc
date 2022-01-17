// Author : Hitesh Kumar
// OS: MAC 
// Editor : VS CODE , gcc

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(){

//printf("GRANDPARENT of all : %d \n",getppid());

int pid,A_pid, B_pid,pid2,C_pid,pid3,pid4;
pid  = fork();

//fflush(stdout);

// To create Nodes A and B
if (pid >0 )  //  A node

{
    wait(NULL);  
    A_pid= getpid();
    printf("__In Node A__ A-id is : %d \n",A_pid);
    //fflush(stdout);
}

else if (pid ==0)  // B node
{  
    B_pid= getpid();
    printf("__In Node B__ B-parent id is :%d \n",getppid());
    //fflush(stdout);
    printf("__In Node B__ B-id is :%d \n",getpid());
    //fflush(stdout);
}
else{
    printf("CANT FORK ! \n");
    //fflush(stdout);
}


pid2= fork();

if(pid2>0)
{
wait(NULL);
}

else if ( pid2 ==0 && getppid()==A_pid){
    C_pid= getpid();
    printf("__In Node C__ C-parent id is :%d \n",getppid());
    //fflush(stdout);
    printf("__In Node C__ C-id is :%d \n",getpid());
    //fflush(stdout);

    // To create Nodes E 
    pid3= fork ();
    if(pid3 ==0){
            printf("__In Node E__ E-parent id is :%d \n",getppid());
            //fflush(stdout);
            printf("__In Node E__ E-id is :%d \n",getpid());
            //fflush(stdout);
    }

    else if(pid3 >0){
        wait(NULL);
        pid4= fork();

        if(pid4 ==0){
            printf("__In Node F__ F-parent id is :%d \n",getppid());
            //fflush(stdout);
            printf("__In Node F__ F-id is :%d \n",getpid());
            //fflush(stdout);

        }

    }

}

else if ( pid2 ==0 && getppid()==B_pid){
    printf("__In Node D__ D-parent id is :%d \n",getppid());
    //fflush(stdout);
    printf("__In Node D__ D-id is :%d \n",getpid());
    //fflush(stdout);
}




} // Main end