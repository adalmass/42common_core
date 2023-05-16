/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:53:18 by aldalmas          #+#    #+#             */
/*   Updated: 2023/05/16 11:05:51 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (lst)
	{
		i++;
		while (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

unsigned char left = (octet << 4)
unsigned char right = (octer >>4)
return (left | right);

return (octet >> 4 + octet << 4);

unsigned char octet;

int i 8;
unsigned char bits;

i > 0
{
	bits = (octet >> i & 1) + '0';
	write (1 , &bits , 1);
	i--;
}

i > 0
ret = ret * 2 + (octet % 2)
octet /=2;
i--;

