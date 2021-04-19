/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:17:54 by ehautefa          #+#    #+#             */
/*   Updated: 2021/01/08 14:31:17 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
