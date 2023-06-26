/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:46:21 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/26 19:20:23 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_command(t_pipex *pp, char *command)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*cmd_path;

	i = 0;
	if (access(command, X_OK) == 0)
		return (command);
	temp = NULL;
	temp2 = NULL;
	cmd_path = NULL;
	while (pp->path[i])
	{
		temp = ft_strdup(pp->path[i]);
		temp2 = ft_strjoin_free(temp, "/");
		cmd_path = ft_strjoin_free(temp2, command);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (command);
}

void	ft_execute(char **cmd, char **av, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{	
		execve(cmd[0], av, envp);
		exit (0);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pp;

	if (ac != 5)
		ft_error("Need 4 args (infile cmd1 cmd2 outfile)");
	init_int(&pp, av);
	check_files(&pp, av);
	init_tabs(&pp, envp);
	pp.cmd1[0] = check_command(&pp, pp.cmd1[0]);
	pp.cmd2[0] = check_command(&pp, pp.cmd2[0]);
	system("leaks pipex");
	exit (0);
	if (access(pp.cmd1[0], X_OK) == 0)
		ft_printf("pipex");
	if (access(pp.cmd2[0], X_OK) == 0)
		ft_printf("pipex");
	ft_printf("cmd1: %s\n", pp.cmd1[0]);
	ft_printf("cmd2: %s\n", pp.cmd2[0]);
}
