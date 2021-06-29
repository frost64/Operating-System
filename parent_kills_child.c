#include <unistd.h>
#include <stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();

    if(pid == 0)
    {
        printf("Child PID = %d\n", pid);
        printf("I am the Child with PID = %d\n", getpid());
        kill(getppid(),SIGTERM);
        sleep(120);
    }

    else if(pid>0)
    {
        wait(NULL);
        printf("Parent of = %d\n", pid);
        printf("I am the Parent with PPID = %d\n",getppid());
    }
}