/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:46:21 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/04 20:25:24 by aldalmas         ###   ########.fr       */
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
	while (pp->path[i])
	{
		temp = ft_strdup(pp->path[i]);
		temp2 = ft_strjoin_free(temp, "/");
		cmd_path = ft_strjoin_free(temp2, command);
		if (access(cmd_path, X_OK) == 0)
		{
			free (command);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (command);
}

void	ft_execute(char **cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, envp) == -1)
		{
			printf("cmd[0]: %s", cmd[0]);
			perror("execve");
		}
		exit (0);
	}
}

void	pipex(t_pipex *pp, char **envp)
{
	int	pipe_tab[2];

	pipe(pipe_tab);
	dup2(pp->infile, 0);
	close(pp->infile);
	dup2(pipe_tab[1], 1);
	close(pipe_tab[1]);
	ft_execute(pp->cmd1, envp);
	dup2(pipe_tab[0], 0);
	close(pipe_tab[0]);
	dup2(pp->outfile, 1);
	close(pp->outfile); 
	ft_execute(pp->cmd2, envp);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pp;

	if (ac < 5)
		ft_error("Need 'infile cmd1 cmd2 outfile' (outfile is optional)'");
	if (!envp)
		perror("No envp");
	init_int(&pp, av);
	check_files(&pp, av);
	init_tabs(&pp, envp);
	pp.cmd1[0] = check_command(&pp, pp.cmd1[0]);
	pp.cmd2[0] = check_command(&pp, pp.cmd2[0]);
	if (access(pp.cmd1[0], X_OK) == 0 && access(pp.cmd2[0], X_OK) == 0)
		pipex(&pp, envp);
	multi_free(pp.cmd1, pp.cmd2, pp.path);
	exit (0);
}
