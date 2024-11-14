/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:47:40 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/14 19:29:35 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_init(int argc, char *argv[], char *envp[]);
void	ft_kids(int tub[2], int argc, char *argv[], char *envp[]);
void	ft_red(char **split, char **argv, char **envp);

#endif