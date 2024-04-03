//This program is called by first part of third
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    printf("This is second prog\n");
    printf("Own PID: %i \n", getpid());
}