/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:27:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/28 15:29:35 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_zeros(t_tabs *tab)
{
	int		y;
	int		temp;

	y = 0;
	while (tab->tab_a[y])
	{
		temp = ft_atoi(tab->tab_a[y]);
		free(tab->tab_a[y]);
		tab->tab_a[y] = ft_itoa(temp);
		y++;
	}
}

void	handle_operators(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (!ft_isdigit(s[i + 1]))
				ft_error("No digit after '-' or '+'\n");
			if (i > 0 && s[i - 1] != ' ')
				ft_error("'+' or '-' after digit\n");
		}
		i++;
	}
}

void	create_tab_a(t_parse *parse, t_tabs *tab)
{
	int		y;
	char	*str;

	y = 1;
	str = ft_strdup("");
	while (parse->args[y])
	{
		str = ft_strjoin_gnl(str, parse->args[y]);
		str = ft_strjoin_gnl(str, " ");
		y++;
	}
	handle_operators(str);
	tab->tab_a = ft_split(str, ' ');
	handle_zeros(tab);
	handle_doubles(tab);
	free(str);
}
