/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:46:21 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/24 11:40:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pp;

	(void)ac;
	init(&pp, envp);
	pp.infile_fd = open(av[1], O_RDONLY);
	if (!pp.infile_fd)
		perror("infile_fd");
	pp.outfile_fd = open(av[4], O_TRUNC | O_CREAT | O_WRONLY);
}
