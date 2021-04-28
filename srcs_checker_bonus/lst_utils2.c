/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:36:41 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/28 11:48:06 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

t_lst	*ft_list_last(t_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

t_lst	*ft_list_last2(t_lst *lst)
{
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

void	ft_list_delone(t_lst *lst)
{
	if (lst)
		free(lst);
}

t_lst	*ft_list_new(int nb)
{
	t_lst	*tab;

	if (!(tab = malloc(sizeof(t_list))))
		return (NULL);
	tab->num = nb;
	tab->next = NULL;
	return (tab);
}
