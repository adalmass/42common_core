/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:07 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/15 11:37:12 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_putchar_ptf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_ptf(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_ptf(s[i]);
		i++;
	}
	return (i);
}

int	ft_strchr_ptf(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_ptf(long long n, char *base, int b_len)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar_ptf('-');
	}
	if (n >= b_len)
		ft_putnbr_ptf(n / b_len, base, b_len);
	ft_putchar_ptf(base[n % b_len]);
}

void	ft_u_putnbr_ptf(unsigned long long n, char *base, int b_len)
{
	if (n >= (unsigned long long)b_len)
		ft_u_putnbr_ptf(n / b_len, base, b_len);
	ft_putchar_ptf(base[n % b_len]);
}
