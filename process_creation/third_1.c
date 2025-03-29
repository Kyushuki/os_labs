//This program calls the second part of third by exec
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    char *argss[]= {'Hello', NULL};
    printf("First prog PID: %i \n", getpid());
    printf("First Parent PID: %i \n", getppid());
    execl("./third2", argss);
    printf("you will not see this caus of exec");
}