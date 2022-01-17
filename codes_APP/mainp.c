// Author : Hitesh Kumar
// OS: MAC 
// Editor : VS CODE , gcc

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(){

//printf("GRANDPARENT of all : %d \n",getppid());
int A_ID;
A_ID=getpid();
printf("**** Parent of all **** : %d\n\n",A_ID);  // A NODE 
fflush(stdout);


int pid_1;
pid_1  = fork();



printf("First fork id : %d \n",pid_1);
fflush(stdout);


if(pid_1 < 0){ 
    printf("forking failed !\n");
    fflush(stdout);
}

else if ((pid_1 >0)&& (getppid()==A_ID)){  // C NODE
    wait(NULL);
    printf("In C node : Parent of C : %d \n",getppid());
    fflush(stdout);
    printf("In C node : C....ID: %d \n",getpid());
    fflush(stdout);
    int pid_1_1 = fork ();


    if(pid_1_1 >0){ 
        wait(NULL); 
        printf("In C node : C -->E ....ID :%d \n",getpid());
        fflush(stdout);
        printf("In C node : C -->E ....ID[PARENT] :%d \n",getppid());
        fflush(stdout);

        }
    else if (pid_1_1 ==0){ 
        printf("In C node : C --> F ....ID :%d \n",getpid());
        printf("In C node : C --> F ....ID[PARENT] :%d \n",getppid());
        fflush(stdout);
        }
    else if(pid_1_1 <0){ 
        printf("Unable to Fork ");
        fflush(stdout);
        }
    else{}
}

else {  // B NODE  pid_1 ==0
    printf("In B node : Parent of B: %d \n",getppid());
    fflush(stdout);
    printf("In B node : B....ID : %d \n",getpid());
    fflush(stdout);
    int pid_1_2 = fork ();
    if(pid_1_2 >0){ 
        wait(NULL); 
        printf("In B node :  B-->D....ID :%d \n",getpid());
        fflush(stdout);
        printf("In B node :  B-->D....ID[PARENT] :%d \n",getppid());
        fflush(stdout);
        }
    //else if (pid_1_2 ==0){ printf("In B node : CHILD-Part of D --> F as its id is :%d \n",getpid());}
    else if (pid_1_2 <0) {printf("Unable to Fork ");fflush(stdout);}
    else{}

}


}