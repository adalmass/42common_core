/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <aldalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:13:19 by aldalmas          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:49 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa_format(char c, long long arg, int *len)
{
	if (c == 'x')
	{
		*len += get_u_nb_len((unsigned int)arg, 16);
		ft_u_putnbr_ptf((unsigned int)arg, "0123456789abcdef", 16);
	}
	if (c == 'X')
	{
		*len += get_u_nb_len((unsigned int)arg, 16);
		ft_u_putnbr_ptf((unsigned int)arg, "0123456789ABCDEF", 16);
	}
}

void	p_format(char c, long long arg, int *len)
{
	if (c == 'p')
	{
		*len += ft_putstr_ptf("0x");
		*len += get_u_nb_len((unsigned long long)arg, 16);
		ft_u_putnbr_ptf((unsigned long long)arg, "0123456789abcdef", 16);
	}
}

void	search_format(char c, long long arg, int *i, int *len)
{
	*i += 1;
	if (c == '%')
		*len += ft_putchar_ptf('%');
	if (c == 'c')
		*len += ft_putchar_ptf((char)arg);
	if (c == 's')
	{
		if (arg == 0)
			*len += ft_putstr_ptf("(null)");
		else
			*len += ft_putstr_ptf((char *)arg);
	}
	if (c == 'd' || c == 'i')
	{
		*len += get_nb_len((int)arg, 10);
		ft_putnbr_ptf((int)arg, "0123456789", 10);
	}
	if (c == 'u')
	{
		*len += get_u_nb_len((unsigned int)arg, 10);
		ft_u_putnbr_ptf((unsigned int)arg, "0123456789", 10);
	}
	hexa_format(c, arg, len);
	p_format(c, arg, len);
}
