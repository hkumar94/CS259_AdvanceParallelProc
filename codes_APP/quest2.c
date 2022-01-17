#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main (void)
{ 
printf("Line 1 ..\n");
fflush(stdout);
write(1,"Line 2 ",7); 
}

//  Be sure there are 7 characters in "Line 2 "