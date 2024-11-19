/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/19 17:33:10 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_red(char **split, char **argv, char **envp)
{
	char	*join;
	int		i;
	int		acc;

	envp = NULL;
	i = 0;
	while (split && split[i] != NULL)
	{
		join = ft_strjoin(split[i], "/");
		join = ft_strjoin(join, argv[1]);
		acc = access(join, F_OK);
		if (acc == 0)
		{
			printf("ok\n");
			break ;
		}
		i++;
	}
	execve(join, ft_split(argv[1], ' '), envp);
	perror("execve failed");
}

	//printf("Hello %s\n", &argv[5]);
	//args[0] = *join;// First argument is the command path
	//args[1] = argv[1];// Next is the first argument to the command
	//args[2] = *envp;


	/** antes de execve() tengo que hacer dup2
	** crear un hijo para cada comando
	** tener en cuenta que me pueden pasar la ruta relativa - absoluta*/
