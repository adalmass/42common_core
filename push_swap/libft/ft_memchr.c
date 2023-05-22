/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:47:07 by aldalmas          #+#    #+#             */
/*   Updated: 2022/11/11 13:47:11 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (c >= 256)
		c -= 256;
	while (i < n)
	{
		if (d[i] == (char)c)
			return (d + i);
		i++;
	}
	return (NULL);
}
