// C program to demonstrate working of wait()
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	if (fork() == 0)
		printf ("HC: hello from child\n");
	else
	{
		printf("HP: hello from parent\n");
		wait();
		printf("CT: child has terminated\n");
	}
	printf("Bye\n");
	return (0);
}
