/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:10:46 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/26 20:52:21 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_while_zero(t_parse *parse)
{
	while (parse->args[parse->y][parse->x]
		&& parse->args[parse->y][parse->x] == '0')
	{
		if (parse->args[parse->y][parse->x + 1] == '\0')
			return (1);
		parse->x++;
	}
	return (0);
}

char	*manage_zeros(t_parse *parse)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (move_while_zero(parse))
		parse->temp = ft_strdup("0");
	while (parse->args[parse->y][parse->x])
	{
		if (parse->args[parse->y][parse->x] < '0'
		|| parse->args[parse->y][parse->x] > '9')
			ft_error();
		parse->temp[j] = parse->args[parse->y][parse->x];
		parse->x++;
		j++;
	}
	parse->temp[j] = '\0';
	return (parse->temp);
}