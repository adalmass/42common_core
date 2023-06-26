/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:33:27 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/25 08:16:04 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_int(t_pipex *pp, char **av)
{
	pp->infile_fd = 0;
	pp->outfile_fd = 0;
	pp->len_envp = 0;
	pp->path_found = 0;
	pp->cmd1 = ft_split(av[2], ' ');
	pp->cmd2 = ft_split(av[3], ' ');
}

void	init_tabs(t_pipex *pp, char **envp)
{
	int	i;

	i = 0;
	while (envp[pp->len_envp])
		pp->len_envp++;
	pp->copy_envp = malloc(pp->len_envp * sizeof(char *));
	if (!pp->copy_envp)
		ft_error("malloc failed : pp,copy_envp");
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pp->path = ft_split(envp[i], ':');
			pp->path_found = 1;
		}
		pp->copy_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (!pp->path_found)
		ft_error("PATH not found");
}

void	check_files(t_pipex *pp, char **av)
{
	pp->infile_fd = open(av[1], O_RDONLY);
	if (pp->infile_fd == -1)
		perror("infile_fd");
	pp->outfile_fd = open(av[4], O_TRUNC | O_CREAT | O_WRONLY);
}
