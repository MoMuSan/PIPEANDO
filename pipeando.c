#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>



int	main(int argc, char *argv[])
{
	int		pipefd[2];
	char	buf;
	pid_t	cpid;

//pq argc[0] es el nombre del programa
//y argc[1] ya es el argumento que le pasamos
	if (argc != 2)
	{
		printf("Error DE ARGUMENTOS %s \n", argv[0]);
		exit (EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit (EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)/*child reads from pipe*/
	{
		close(pipefd[1]); /*close unused write end*/
		while (read(pipefd[0], &buf, 1) > 0)
		{
			write(STDOUT_FILENO, &buf, 1);
			write(STDOUT_FILENO, "\n", 1);
			close(pipefd[0]);
			exit (EXIT_SUCCESS);
		}
	}
	
}
