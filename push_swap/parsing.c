/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/24 21:48:12 by aldalmas         ###   ########.fr       */
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

int	search_double(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len_s1;
	int	len_s2;

	i = 0;
	len_s1 = s_len(s1);
	len_s2 = s_len(s2);
	if (len_s1 == len_s2)
	{
		while (s1[i])
		{
			j = 0;
			while (s1[i + j] == s2[j] && s1[i] && s2[i])
			{
				if (j == len_s2)
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	find_double(t_tabs *tabs, char *chars_stocked, int here)
{
	int	x;
	int	y;

	y = 0;
	(void) chars_stocked;
	while (tabs->tab_a[y])
	{
		x = 0;
		if (y != here)
		{
			if (search_double(tabs->tab_a[y], chars_stocked))
				ft_error();
		}
		y++;
	}
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
		find_double(tabs, chars_stocked, y);
		free(chars_stocked);
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

