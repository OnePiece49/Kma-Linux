#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	static pid_t child;
	if(child >= 0)
	{	
		if(child == 0)
		{
			printf("I'm tien trinh con co PID con %d va PID bo : %d\n",getpid(), getppid());
		}
		if(child > 0)
		{
			printf("My PID la %d\n",getpid());
		}
	}
	else
		printf("faild\n");
	return 0;
}
