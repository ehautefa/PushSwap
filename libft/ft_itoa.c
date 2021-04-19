/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:16:29 by ehautefa          #+#    #+#             */
/*   Updated: 2020/12/06 12:53:50 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_count_char(int n)
{
	int				i;
	unsigned int	num;

	i = n >= 0 ? 0 : 1;
	num = n >= 0 ? n : -n;
	while (num >= 1)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				size;
	unsigned int	num;

	i = 1;
	size = n != 0 ? ft_count_char(n) : 1;
	num = n >= 0 ? n : -n;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[0] = n != 0 ? '-' : '0';
	while (num >= 1)
	{
		str[size - i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}
