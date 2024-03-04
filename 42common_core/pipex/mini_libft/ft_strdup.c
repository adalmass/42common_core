/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:45:26 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/23 20:24:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*d;

	d = malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, ft_strlen(s1));
	d[ft_strlen(s1)] = '\0';
	return (d);
}
