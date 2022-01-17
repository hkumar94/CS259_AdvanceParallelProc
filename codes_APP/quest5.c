#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main () 
{
int pid;
int i;
for (i=0; i<3; i++){
if ((pid=fork()) <0 ) {printf("Sorry...cannot fork\n"); }
else if (pid ==0)  {printf("child %d\n", i);
fflush(stdout); }
else  {wait(NULL);
printf ("parent %d\n", i);
fflush(stdout); }
}
exit(0);}