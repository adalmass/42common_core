/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:24:55 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 14:46:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_error(char *error_msg)
{
	//ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit (1);
}

void	init_struct(t_parse *p)
{
	p->count = 0;
	p->len_cmd_line = 0;
	p->redir_l_count = 0;
	p->redir_r_count = 0;
	p->pipe_count = 0;
	p->pip_first_error = 0;
	p->redir_first_error = 0;
}

void    prompt(void)
{
    t_parse p;
    using_history();
    
    while (1)
    {
        p.cmd_line = readline("MiniCHEH: ");
        parsing(&p);
        // exec();
        if (p.cmd_line)
            add_history(p.cmd_line);
        free(p.cmd_line);
    }
    free(p.cmd_line);
    //parsing(av[1]);
}
