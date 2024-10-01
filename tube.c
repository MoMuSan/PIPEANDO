#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		fd[2]; //two ends of the pipe
	char	mess[] = "Hello";
	char	buffer[100];
	pid_t	pid;

//create the pipe
	if (pipe(fd) == -1)
	{
		perror("Pipe failed\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed\n");
		return (1);
	}
	if (pid == 0) //Child process
	{
		close(fd[0]); //close reading end
		write(fd[1], mess, strlen(mess) + 1); //write message to the pipe
		close(fd[1]); // close the write end, after writing
	}
	else //Parent process
	{
		close(fd[1]); //close writing end
		read(fd[0], buffer, sizeof(buffer)); //Read from pipe
		printf("Parent rceived %s\n", buffer);
		close(fd[0]); //close read end afer reading
	}
	return (0);
}
