#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	redir(void)
{
	int		fd[2];
	pid_t	pid;
	int		op;
	int		op2;
	char	*args[3];
	char	*argu[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	argu[0] = "cat";
	argu[1] = "-e";
	argu[2] = NULL;
	if (pipe(fd) == -1)
	{
		perror("Pipe error\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error\n");
		return (1);
	}
	if (pid == 0)
	{
		op = open("/bin/ls", O_RDWR);
		if (op < 0)
			return (1);
		dup2(op, 0);
		close(fd[0]);
		dup2(fd[1], 1);
		execve("/usr/bin/ls", args, NULL);
	}
	op2 = open("file2.txt", O_RDWR | O_CREAT, 0777);
	if (op2 < 0)
		return (1);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(op2, 1);
	execve("/bin/cat", argu, NULL);
	return (0);
}

/*int access(const char *pathname, int mode);
int execve (const char *filename, const char *argv[], const char *envp[]);
printf("\n%s\n", *split);
	
	printf("ARGC %d ARGV %s\n", argc, *argv);
	//número de argumentos -- 
	nombre del primer argumento (porque no he señalado ningún otro)
	
	join = ft_strjoin(*split, *split);
	printf("%s\n", join);
	acc = access(join, X_OK);
	if (acc < 0)
		printf ("ERROR\n");
	else
		printf ("VALIDO\n");
	execve(join, argv, envp);
	if (execve(join, argv, envp) < 0)
		perror ("NO FILE\n");
	else
		printf("Bien\n");	
	return (0);*/