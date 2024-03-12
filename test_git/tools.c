/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:24:55 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/09 12:24:57 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *error_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit (1);
}

void	ft_free(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free (tab[y]);
		y++;
	}
	free (tab);
}

void	multi_free(char **cmd1, char **cmd2, char **path)
{
	ft_free(cmd1);
	ft_free(cmd2);
	ft_free(path);
}
