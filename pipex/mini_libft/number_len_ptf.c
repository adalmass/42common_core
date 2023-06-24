/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_len_ptf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:40:31 by aldalmas          #+#    #+#             */
/*   Updated: 2023/06/24 10:07:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	get_nb_len(long long n, int b_len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= b_len)
	{
		n /= b_len;
		i++;
	}
	i++;
	return (i);
}

int	get_u_nb_len(unsigned long long n, int b_len)
{
	int	i;

	i = 0;
	while (n >= (unsigned long long)b_len)
	{
		n /= b_len;
		i++;
	}
	i++;
	return (i);
}
