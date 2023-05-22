/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/22 18:27:01 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char_args(char c, char d)
{
	if ((c >= '0' && c <= '9')
		|| (c == '+' && (d >= '0' && d <= '9'))
		|| (c == '-' && (d >= '0' && d <= '9')))
		return (1);
	return (0);
}

// je verifie s'il n'y a pas de doublons en stockant chaque caractere dans un tableau, 
// qui me servira de reference pour un strchr maison dans find_double()
void	check_if_double(t_parse *parse, t_tabs *tabs)
{
	int		y;
	char	*chars_stocked;

	(void)	parse;
	y = 0;
	while (tabs->tab_a[y])
	{
		chars_stocked = ft_strdup(tabs->tab_a[y]);
		JE DOIS TROUVER COMMENT CHECKER LES DOUBLONS ICI
		// chars_stocked = ft_strjoin_gnl(chars_stocked, tabs->tab_a[y + 1]);
		// chars_stocked = ft_strjoin_gnl(chars_stocked, "\n");
		// ft_putstr(chars_stocked);
		y++;
	}
}

// jai besoin de creer le tableau pour ensuite verifier si je nai pas de doubles
void	create_tab_a(char **av, t_parse *parse, t_tabs *tabs)
{
	int		y;
	char	*temp;

	y = 1;
	temp = ft_strdup("");
	while (av[y])
	{
		temp = ft_strjoin_gnl(temp, av[y]);
		temp = ft_strjoin_gnl(temp, "\n");
		y++;
	}
	tabs->tab_a = ft_split(temp, '\n');
	check_if_double(parse, tabs);
}
