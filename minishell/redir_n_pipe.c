/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_n_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:48:46 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 10:09:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    redir_left(t_parse *p, char next_char)
{
    p->redir_l_count++;
    if (next_char != '\0' && next_char != '<')
        check_redir_n_pipes(p);
}

void    redir_right(t_parse *p, char next_char)
{
    p->redir_r_count++;
    if (next_char != '\0' && next_char != '>')
        check_redir_n_pipes(p);
}

void    check_pipe(t_parse *p, char next_char)
{
        p->pipe_count++;
    if (next_char != '\0' && next_char != '|')
        check_redir_n_pipes(p);
}

void    check_first_char(t_parse *p)
{
    int i;

    i = 0;
    i = check_jsp(p, i, '|');
    i = check_jsp(p, i, '<');
    i = check_jsp(p, i, '>');
}

// sert a verifier les lignes de commandes comme "ls >", qui terminent par une redir ou un pipe
void    check_last_char(t_parse *p)
{
    ;
}
