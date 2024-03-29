/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:59:37 by aldalmas          #+#    #+#             */
/*   Updated: 2022/11/23 08:13:40 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_nblen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	append_str(char *str, size_t len, int n)
{
	while (n > 9)
	{
		str[len] = n / 10 + '0';
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (n <= 9)
	{
		str[len] = n + '0';
		if (len != 0)
			len--;
	}
}

char	*ft_itoa(int n)
{
	static size_t	len;
	static char		*str;

	len = get_nblen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		if (n != 0)
			str[0] = '-';
		n *= -1;
	}
	append_str(str, len, n);
	return (str);
}
