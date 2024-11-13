/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/13 22:54:08 by monmunoz         ###   ########.fr       */
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
		join = ft_strjoin(join, argv[1]);
		acc = access(join, 0111);
		if (acc == 0)
			break ;
		i++;
	}

	printf("%s %s \n", argv[1], join);
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


	** antes de execve() tengo que hacer dup2
	** crear un hijo para cada comando
	** tener en cuenta que me pueden pasar la ruta relativa - absoluta
	
	