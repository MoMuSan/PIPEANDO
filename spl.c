#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_pipex.h"
#include "libft/libft.h"


int main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**split;
	int		acc;
	char	*join;

	split = NULL;
	i = 0;
	if (argc == 1)
	{
		printf("No argument\n");
		return (1);
	}
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			split = ft_split(&envp[i][5], ':');
		i++;
	}
	i = 0;
	while (split && split[i] != NULL)
	{
		join = ft_strjoin(split[i], "/");
		join = ft_strjoin(join, argv[1]); //join es la ruta
		acc = access(join, 0111);
		//paso solo permisos de execution porque si no existe, no hay nada que hacer
		if (acc == 0) //acc me dice si encuentra argv[1] en join
			break ;
		i++;
	}
	execve(join, &argv[1], envp);
	printf("ARGC= %d ARGV= %s\n", argc, *argv);
	return (0);
}
//le paso la dirección, porque le estoy especificando
//la segunda coordenada (que se corresponde con el tamaño de PATH=)

if (second_son == 0)
		{
			ft_kid_two(tub, &argv[3], envp, path);
		}
	Es argv[3], porque en este punto del programa, aun sigo 
	contando desde el inicio