/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:50:05 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 15:15:11 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    create_cmds_table(t_parse *p)
{
    int     x;
    int     y;
    char    *temp;

    x = 0;
    y = 0;
    temp = NULL;
    p->cmd_table = ft_split(p->cmd_line, '|');
    while (p->cmd_table[y])
    {
        if (temp)
            free (temp);
        temp = ft_strtrim(p->cmd_table[y], " ");
        handle_spaces(p, y);
        // verifier le bon nb d'espace entre les < ou > sinon refaire comme il faut
        // verifier si la commande n'est pas collee, si oui, rajouter un espace entre chaque mot et redir
     
        printf("temp:%s\nlen: %d\n", temp, ft_strlen(temp));
        y++;
    }
    if (temp)
        free (temp);
}
    // while (p->cmd_table[y])
    // {
    //     printf("%s\n", p->cmd_table[y]);
    //     y++;
    // }

// FONCTION PRINCIPALE
void    parsing(t_parse *p)
{
    //get_valid_cmdline(&p);// a creer, verifier s'il n'y a pas d'espaces avant la ligne de commande
    init_struct(p);
    create_cmds_table(p); // je recupere les commandes une par une, separees par un |
    //check_first_char(p);
    //check_cmd_line(p); // premiere etape, verif si la cmd line est bien ecrite
    //command_table(p);  // derniere etape, creer la command table et la donner a Bechir
}

// main a supprimer apres avoir fini et renommer ce fichier en parse.c
int main()
{
    prompt();   
}
