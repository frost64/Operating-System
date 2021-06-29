#include <unistd.h>
#include <stdlib.h>


int main()
{
    int pid;
    int pfd[2];
    char aString[20];
    pipe(pfd);
    pid = fork();
    if (pid == 0) // Child
    {
        close(pfd[0]);
        write(pfd[1], system("Hello"), 5); // Input to pipe
    }
    else // Parent
    {
        close(pfd[1]);
        read(pfd[0], aString, 05); // Output of pipe
    }
}