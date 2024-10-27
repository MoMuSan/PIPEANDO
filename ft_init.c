/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:48 by monmunoz          #+#    #+#             */
/*   Updated: 2024/10/27 22:51:38 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		tub[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		return (1);
	}
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		perror("pipex");
		return (1);
	}
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
		ft_putstr_fd("Hijo \n", 1);
	return (0);
}

/*	supera las 25 líneas.
	Podría hacer una función para los errores
	y contiuar a partir de la línea 43, para empezar a gestionar 
	al padre y al hijo.*/
