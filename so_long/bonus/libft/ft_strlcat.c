/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:56:03 by aldalmas          #+#    #+#             */
/*   Updated: 2022/11/27 15:27:36 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_s;

	i = 0;
	j = 0;
	len_s = ft_strlen(src);
	if (!dstsize)
		return (len_s);
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize == i && dst[i] != 0)
		return (dstsize + len_s);
	while (src[j] && ((i + j) < dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len_s + i);
}
