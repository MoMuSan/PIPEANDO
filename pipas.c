#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int	fd;
	fd = open("example.txt", O_WRONLY | O_CREAT); 
	//O_CREAT crea el archivo si no existe
	dup2(fd, STDOUT_FILENO);
	//STDOUT_FILENO es un int, un fd (el 1 aquí).
	//redirige la salida del terminal al fd.
	close(fd);
	printf("This is it!!\n");
	//lo muestra en el archivo, no en pantalla
	return (0);
}
// Ejemplo de access 
/*{
	if (access("example.txt", X_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");

	return (0);
}*/
// Ejemplo de execve
/*{
	char *args[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
	return (0);
}*/

//fork

/*{
	pid_t	pid = fork();
	// fork creates a child process

	if (pid < 0)
// Error occurred
	{
		printf("Fork failed!\n");
		return (1);
	}
	else if (pid == 0)
  // Child process
	{
		printf("Child process. PID: %d\n", pid);
	}
	else
	{
 // Parent process
		printf("Parent process. PID: %d, Child PID: %d\n", pid, pid);
	}
	return (0);
}
*/

/*{
	pid_t	pid = fork();

	if (pid == 0)
	{
// Child process
		printf("Child process. PID: %d\n", getpid());
	}
	else
	{
// Parent process
		wait(NULL);
// Wait for the child to complete
		printf("Parent process. Child PID: %d finished.\n", pid);
	}
	return (0);
}*/
