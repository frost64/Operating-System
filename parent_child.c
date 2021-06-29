#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <stdlib.h>

int main(){

int pid;
pid = fork(); 
	if(pid>0){                                // This is Parent
		printf("Parent is waiting->\n");     // Parent is running here
		wait(NULL);		                      // Parent is waiting and from here the control is passed to child
		printf("Parent is resuming->\n");    // Parent is resuming after the child is exited
	}
	if (pid==0){                              // This is Child
		printf("Child is exiting->\n");      // Child is running here
		exit(0);                              // Child is exiting and control is passed back to the parent
	}
	return 0;
}
