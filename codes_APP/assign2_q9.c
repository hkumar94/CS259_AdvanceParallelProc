#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int signum){
  printf("\nWaiting for input ..\n");
  break;
}
int main(){
signal(SIGALRM,sig_handler); 
alarm(10);  // Scheduled - 10 seconds
int i;
printf("Enter mobile number : ");
scanf("%d",&i);
alarm(0);   
return 0;
}