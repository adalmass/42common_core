/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:50:17 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/04 19:53:09 by aldalmas         ###   ########.fr       */
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

void	ft_free(char **split)
{
	int	y;

	y = 0;
	while (split[y])
	{
		free (split[y]);
		y++;
	}
	free (split);
}

void	multi_free(char **cmd1, char **cmd2, char **path)
{
	ft_free(cmd1);
	ft_free(cmd2);
	ft_free(path);
}
