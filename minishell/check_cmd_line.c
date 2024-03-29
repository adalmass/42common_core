/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:38:26 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 11:39:13 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    check_redir_n_pipes(t_parse *p)
{
    if (p->redir_l_count >= 6)
        parse_error("bash: syntax error near unexpected token `<<<'");
    else if (p->redir_l_count == 5)
        parse_error("bash: syntax error near unexpected token `<<'");
    else if (p->redir_l_count == 4)
        parse_error("bash: syntax error near unexpected token `<'");
    if (p->redir_r_count == 3)
        parse_error("bash: syntax error near unexpected token `>'");
    else if (p->redir_r_count >= 4)
        parse_error("bash: syntax error near unexpected token `>>'");
    if (p->pipe_count == 3)
        parse_error("bash: syntax error near unexpected token `|'");
    else if (p->pipe_count > 3)
        parse_error("bash: syntax error near unexpected token `||'");
    else if (p->pipe_count == 2)
        parse_error("minishell without bonus: syntax error near unexpected token `||'");
}

// premiere etape du parsing
// On verifie combien il y a de commandes et si elles sont separees par des espaces
void    check_cmd_line(t_parse *p)
{
    int i;

    i = 0;
    while (p->cmd_line[i])
    {
        if (p->cmd_line[i] == '<')
            redir_left(p, p->cmd_line[i]);
        else if (p->cmd_line[i] == '>')
        {
            p->redir_r_count++;
            if (p->cmd_line[i + 1] && p->cmd_line[i + 1] != '>')
                check_redir_n_pipes(p);
        }
        else if (p->cmd_line[i] == '|')
        {
            p->pipe_count++;
            if (p->cmd_line[i + 1] && p->cmd_line[i + 1] != '|')
                check_redir_n_pipes(p);
        }
        i++;
    }
    p->len_cmd_line = i;
}

int    check_jsp(t_parse *p, int i, char c)
{
    while (p->cmd_line[i] == c)
    {
        if (c == '|')
            p->pipe_count++;
        else if (c == '<')
            p->redir_l_count++;
        else if (c == '>')
            p->redir_r_count++;
        i++;
    }
    check_redir_n_pipes(p);
    return (i);
}