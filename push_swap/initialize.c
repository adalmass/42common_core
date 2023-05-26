/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:21:47 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/26 20:49:00 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_struct(t_parse *parse)
{
	parse->found = 0;
	parse->len_to_find = 0;
	parse->y = 0;
	parse->x = 0;
	parse->temp = ft_strdup("");
}

