/*---------------------------------------------------------------------
Description:
------------
	If the parent is dead before the child then the child will be 
orphaned, so it needs a new parent which will be assigned to init.
Now init will be the new parent of the orphaned child.

---------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int pid;
	pid=fork();
	if(pid>0) //   Parent
	{
		sleep(1);
		exit(0);
	}
	else if(pid == 0) //  Child
	{
		printf("Current Parent: %d\n",getppid());  //  current parent of the child
		sleep(2);
		printf("New Parent: %d\n",getppid()); //  child associated to init after the  parent is dead
	}
}
