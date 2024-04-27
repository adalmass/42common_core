/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:02:16 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 16:01:00 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int is_redir(char c)
{
    if (c == '>' || c == '<')
        return (1);
    return (0);        
}

void    update_cmd_table(t_parse *p, char *new_cmd, int cmd_idx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (p->cmd_table[cmd_idx][j] && !is_redir(p->cmd_table[cmd_idx][j]))
    {            
        new_cmd[i] = p->cmd_table[cmd_idx][j];
        i++;
        j++;
    }
    if (is_redir(p->cmd_table[cmd_idx][j]))
    {
        new_cmd[i] = ' ';
        new_cmd[i + 1] = p->cmd_table[cmd_idx][j];
        i += 2;
    }
    while (p->cmd_table[cmd_idx][j] && is_redir(p->cmd_table[cmd_idx][j]))
        j++;
    while (ft_isalnum(p->cmd_table[cmd_idx][j]))
    {            
        new_cmd[i] = p->cmd_table[cmd_idx][j];
        i++;
        j++;
    }
    printf("new_cmd (update_cmd_table()): %s\n", new_cmd);
}

// si "cat>ls"
void    no_spaces(t_parse *p, int cmd_idx)
{
    int     i;
    int     redir_found;
    char    *new_cmd;

    i = 0;
    redir_found = 0;
    new_cmd = NULL;
    while (p->cmd_table[cmd_idx][i])
    {
        if (is_redir(p->cmd_table[cmd_idx][i]))
            redir_found++;
        i++;
    }
    i = 0;
    if (redir_found)
    {    
        printf("redir trouvé\n");
        new_cmd = malloc(sizeof(char) * ft_strlen(p->cmd_table[cmd_idx]) + 3); // + 3 pour ajouter un espace devant et apres la redir
        update_cmd_table(p, new_cmd, cmd_idx);
    }
}

void    too_many_spaces(t_parse *p, int cmd_idx)
{
    ;
}

int    count_spaces(char *str)
{
    int i;
    int space_nb;

    i = 0;
    space_nb = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            space_nb++;
        i++;
    }
    return (space_nb);
}

void    handle_spaces(t_parse *p, int cmd_idx)
{
    int space_nb;

    space_nb = count_spaces(p->cmd_table[cmd_idx]);
    if (space_nb == 0)
        no_spaces(p, cmd_idx);// creer une fonction qui ajoue les espaces;
    else if (space_nb > 1)
        too_many_spaces(p, cmd_idx);// fonction qui modif la str pour qu'il y ait qu'un espace entre la commande et la redir
}
