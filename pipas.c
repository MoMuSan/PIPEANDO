#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
/*{
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
}*/
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

{
	fork();
	fork();
	if (fork()< 0)
		printf("Hello\n");
	else
		printf("Error\n");
	return (0);
}