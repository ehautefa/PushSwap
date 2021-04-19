/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:16:04 by ehautefa          #+#    #+#             */
/*   Updated: 2020/12/21 18:37:25 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (!(ret = (void *)malloc(count * size)))
		return (NULL);
	ret = ft_memset(ret, 0, count * size);
	return (ret);
}
