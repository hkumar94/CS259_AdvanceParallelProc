#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){


printf("Parent of all: %d\n",getpid());
fflush(stdout);
int pid_1;
pid_1  = fork();

printf("First fork id : %d \n",pid_1);
fflush(stdout);



if(pid_1 < 0){
    printf("forking failed !\n");
    fflush(stdout);
}

else if (pid_1 ==0){  // child C
    //printf("-------- in child - C ----------");
    printf("In C block : Parent of C : %d \n",getppid());
    fflush(stdout);
    printf("In C block : C -----> : %d \n",getpid());
    fflush(stdout);
    int pid_1_1 = fork ();
    //printf("Parentid : %d \n",pid_1);

    if(pid_1_1 >0){ printf("In C block : PARENT-Part of C -->E as its id is :%d \n",getpid());fflush(stdout);}
    else if (pid_1_1 ==0){ printf("In C block : CHILD-Part of C --> F as its id is :%d \n",getpid());fflush(stdout);}
}
else {
    printf("Parent id in D : %d \n",getppid());
    fflush(stdout);
    printf("D -----> : %d \n",getpid());
    fflush(stdout);
}


}