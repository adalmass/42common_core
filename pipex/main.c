/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:46:21 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/25 11:36:02 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_command(t_pipex *pp, char *command)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (pp->path[i])
	{
		temp = ft_strjoin(pp->path[i], "/");
		temp = ft_strjoin(temp, command);
		if ((access(temp, X_OK) == 0))
			break ;
		i++;
	}
	if (!pp->path[i] && (access(temp, X_OK) == -1))
		return (NULL);
	return (temp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pp;

	if (ac != 5)
		ft_error("Need 4 args (infile cmd1 cmd2 outfile)");
	init_int(&pp);
	init_tabs(&pp, envp);
	check_files(&pp, av);
	// je verifie si les cmd1 et cmd2 existent et sont executables
	// access renvoie -1 si ce n'est pas le cas et 0 si ça l'est
	// cette verif a ce stade du code est necessaire au cas où l'user 
	// met directement le chemin complet de la commande
	pp.path = ft_split(pp.copy_envp[pp.path_idx] + 5, ':'); // le + 5 est pour enlever PATH= devant la premiere str
	if (access(av[2], X_OK) == -1)
	{
		pp.cmd1 = check_command(&pp, av[2]);
		if (pp.cmd1 == NULL)
			pp.cmd1 = ft_strdup(av[2]);
	}
	if (access(av[3], X_OK) == -1)
	{
		pp.cmd2 = check_command(&pp, av[3]);
		if (pp.cmd2 == NULL)
			pp.cmd2 = ft_strdup(av[3]);
	}
	ft_printf("cmd1: %s\n", pp.cmd1);
	ft_printf("cmd2: %s\n", pp.cmd2);
}
