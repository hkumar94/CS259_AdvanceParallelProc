#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define BUFFERSIZE 20

int main(){
    int pipeData[2];
    char msg[BUFFERSIZE];
    char buf[BUFFERSIZE];
    
    if(pipe(pipeData) == -1){
        perror("pipe error occured");
        exit(EXIT_FAILURE);
    }
    //writing starts
    if(fork() == 0){
        //child
        close(pipeData[1]);
        read(pipeData[0], buf, BUFFERSIZE);
        printf("This is child process reading first message. Content is :%s\n", buf);
        read(pipeData[0], buf, BUFFERSIZE);
        printf("This is child process reading second message. Content is :%s\n", buf);
        read(pipeData[0], buf, BUFFERSIZE);
        printf("This is child process reading third message. Content is :%s\n", buf);
        read(pipeData[0], buf, BUFFERSIZE);
        printf("This is child process reading fourth message. Content is :%s\n", buf);

        close(pipeData[0]);

        exit(EXIT_SUCCESS);

    }
    // parent process
    close(pipeData[0]);
    sprintf(msg , "San");
    printf("This is parent process. Writing first message into pipe\n");
    write(pipeData[1], msg, BUFFERSIZE);
    sprintf(msg , "Jose");
    printf("This is parent process. Writing second message into pipe\n");
    write(pipeData[1], msg, BUFFERSIZE);
    sprintf(msg , "State");
    printf("This is parent process. Writing third message into pipe\n");
    write(pipeData[1], msg, BUFFERSIZE);
    sprintf(msg , "University");
    printf("This is parent process. Writing fourth message into pipe\n");
    write(pipeData[1], msg, BUFFERSIZE);
    close(pipeData[1]);
    wait(NULL);

    return 0;
  
}