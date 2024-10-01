#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>



int	main(int argc, char *argv[])
{
	int		pipefd[2];
	char	buf;
	pid_t	cpid;

//pq argc[0] es el nombre del programa
//y argc[1] ya es el argumento que le pasamos
	if (argc != 2)
	{
		printf("ERROR DE ARGUMENTOS %s \n", argv[0]);
		exit (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit (1);
	}

	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (cpid == 0) /*child reads from pipe*/
	{
		close(pipefd[1]);/*close unused write end*/
		while (read(pipefd[0], &buf, 1) > 0)
			write(1, &buf, 1);
		write(1, "\n", 1);
		close(pipefd[0]);
		exit (0);
	}
	else /*parent writes argv[1] to pipe*/
	{
		close(pipefd[0]); /*close unused read end*/
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]); /*reader willl see EOF*/
		//wait(NULL); /*wait for child*/
		exit (0);

	}
}

