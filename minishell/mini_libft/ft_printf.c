/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:08:34 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/15 17:42:18 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;	
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr_ptf("cspdiuxX", s[i + 1]))
			search_format(s[i + 1], va_arg(arg, long long), &i, &len);
		else if (s[i] == '%' && s[i + 1] == '%')
			search_format(s[i + 1], 1, &i, &len);
		else
			len += ft_putchar_ptf(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
