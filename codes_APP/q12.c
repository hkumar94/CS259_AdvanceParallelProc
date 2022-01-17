#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
typedef struct sigaction Sigaction;
unsigned long long size = 0;

void alarm_func(int sig){
    printf("Write blocked after %llu characters. \n", size);
}

int main(){
    int pipefd[2];
    if(pipe(pipefd) == -1){
        perror("pipe");
    }
    sigset_t mask , prev;
    sigemptyset(&mask);
    sigaddset(&mask , SIGALRM);
    sigprocmask(SIG_BLOCK , &mask , &prev);
    Sigaction new_action;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = SA_RESTART;
    new_action.sa_handler = alarm_func;
    sigaction(SIGALRM , &new_action , NULL);
    sigprocmask(SIG_SETMASK , &prev, NULL);
    while(1){
        if(size != 0 && size % 1024 == 0){
            printf("%llu characters in pipe\n", size);
        }
        alarm(0);
        alarm(4);
        write(pipefd[1], "A", sizeof(char));
        size++;
    }
    return 0;
  
}

