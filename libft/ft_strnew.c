/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:18:55 by ehautefa          #+#    #+#             */
/*   Updated: 2021/01/21 11:51:38 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while ((int)size >= 0)
	{
		str[(int)size] = '\0';
		size--;
	}
	return (str);
}
