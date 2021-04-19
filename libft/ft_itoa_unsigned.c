/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:16:29 by ehautefa          #+#    #+#             */
/*   Updated: 2021/01/21 10:48:26 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_count_char(unsigned int num)
{
	int				i;

	i = 0;
	while (num >= 1)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_unsigned(unsigned int num)
{
	int				i;
	char			*str;
	int				size;

	i = 1;
	size = num != 0 ? ft_count_char(num) : 1;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[0] = num != 0 ? '-' : '0';
	while (num >= 1)
	{
		str[size - i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}
