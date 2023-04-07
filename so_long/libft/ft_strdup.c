/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:00 by aldalmas          #+#    #+#             */
/*   Updated: 2022/11/11 17:25:03 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
