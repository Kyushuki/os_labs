//This program gives the PID of the current and parent processes 
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    printf("Own PID: %i \n", getpid());
    printf("Parent PID: %i \n", getppid());
}