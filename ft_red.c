/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/14 20:53:23 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_red(char **split, char **argv, char **envp)
{
	char	*join;
	int		i;
	int		acc;
	char	**args;

	envp = NULL;
	args = NULL;
	i = 0;
	while (split && split[i] != NULL)
	{
		join = ft_strjoin(split[i], "/");
		join = ft_strjoin(join, argv[2]);
		printf("acc %s\n", join);
		acc = access(join, F_OK); 
		if (acc == 0)
		{
			printf("ok\n");
			break ;
		}
		i++;
	}

	printf(" HOLA JOIN %s \n", join);
	args[0] = join;
	args[1] = argv[1];
	args[2] = 0;
	execve(join, args, envp);
	perror("execve failed");
}

	//printf("Hello %s\n", &argv[5]);
	//args[0] = *join;// First argument is the command path
	//args[1] = argv[1];// Next is the first argument to the command
	//args[2] = *envp;


	/** antes de execve() tengo que hacer dup2
	** crear un hijo para cada comando
	** tener en cuenta que me pueden pasar la ruta relativa - absoluta*/
