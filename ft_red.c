/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:45:43 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/24 20:24:45 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_red_in(char **path, char **cmd1, char **envp)
{
	char	*join;
	int		i;

	envp = NULL;
	i = 0;
	if (ft_strrchr(cmd1[0], '/') != 0)
		join = cmd1[0];
	else
	{
		while (path && path[i] != NULL)
		{
			join = ft_strjoin(path[i], "/");
			join = ft_strjoin(join, cmd1[0]);
			if (access(join, F_OK) == 0)
				break ;
			i++;
		}
	}
	execve(join, cmd1, envp);
	perror("Error execve");
	exit (1);
}
