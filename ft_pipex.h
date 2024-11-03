/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monmunoz <monmunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:47:40 by monmunoz          #+#    #+#             */
/*   Updated: 2024/11/03 21:08:13 by monmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_init(int argc, char *argv[], char *envp[]);
void	ft_kids(int argc, char *argv[], char *envp[]);

#endif