/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:16:54 by ehautefa          #+#    #+#             */
/*   Updated: 2020/09/16 09:16:56 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	if (!(tab = malloc(sizeof(t_list))))
		return (NULL);
	if (!(tab->content = (void *)malloc(sizeof(content))))
		return (NULL);
	if (!(tab->next = malloc(sizeof(t_list))))
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
