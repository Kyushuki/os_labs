//This program gives the PID of the current and parent processes and creates a copy of itself
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    while(1)
    {
        printf("Press CRTL+C to stop!");
        printf("Own PID: %i \n", getpid());
        printf("Parent PID: %i \n", getppid());
        fork();
    }
    
}