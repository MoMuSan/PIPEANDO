/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:48 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/20 14:58:30 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_init(int argc, char *argv[], char *envp[])
{
	int		tub[2];
	pid_t	pid;

	if (pipe(tub) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return (1);
	}
	if (pid == 0)
		ft_kids(tub, argc, &argv[1], envp);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
// 	int		i;
// 	char	**cmd1;

// 	i = 0;
	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	ft_init(argc, argv, envp);
	return (0);
}

ft_spaces
{
	while (argv[2])
	{
		if (argv[2][i] == ' ')
			cmd1 = ft_split(&argv[2][i], ' ');
		else
		{
			printf("HELLO\n");
			break ;
		}
		i++;
	}
	if (cmd1)
	{
		ft_init(argc, cmd1, envp);
		printf("CMD %s\n", cmd1[0]);
		printf("CMD1 %s\n", cmd1[1]);
	}
}