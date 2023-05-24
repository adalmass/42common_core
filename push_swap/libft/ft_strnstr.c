/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:47 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/24 21:32:49 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (0);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && (i <= len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && ((i + j) < len) && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
