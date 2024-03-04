/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:46:07 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/30 17:31:10 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_int(t_pipex *pp, char **av)
{
	pp->infile = 0;
	pp->outfile = 0;
	pp->path_found = 0;
	pp->cmd1 = ft_split(av[2], ' ');
	pp->cmd2 = ft_split(av[3], ' ');
}

void	init_tabs(t_pipex *pp, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pp->path = ft_split(envp[i], ':');
			pp->path_found = 1;
		}
		i++;
	}
	if (!pp->path_found)
		ft_error("PATH not found");
}

void	check_files(t_pipex *pp, char **av)
{
	pp->infile = open(av[1], O_RDONLY, (S_IRUSR | S_IWUSR));
	if (pp->infile == -1)
		perror("infile");
	pp->outfile = open(av[4],
			O_TRUNC | O_CREAT | O_WRONLY, (S_IRUSR | S_IWUSR));
	if (pp->outfile == -1)
		perror("outfile");
}
