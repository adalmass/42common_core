/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:07:10 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/24 11:30:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	search_str(char	*haystack, char *needle)
{
	int	i;
	int	j;
	int	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && (needle[j] == haystack[i + j]))
		{
			if (j == len_needle)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
