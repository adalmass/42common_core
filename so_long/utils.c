/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:53 by aldalmas          #+#    #+#             */
/*   Updated: 2023/04/27 14:03:44 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_char(char *haystack, char needle)
{
	size_t	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
		{
			if (haystack[i] == '\n' && haystack[i + 1] != '\0')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}
