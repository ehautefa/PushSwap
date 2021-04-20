/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:36:41 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/20 17:48:46 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		ft_list_add_back(t_lst **alst, t_lst *new)
{
	t_lst	*last;

	if (new == NULL)
		return (-1);
	if (alst == NULL)
	{
		alst = &new;
		return (0);
	}
	last = ft_list_last(*alst);
	last->next = new;
	return (0);
}

void	ft_list_add_front(t_lst **alst, t_lst *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_list_clear(t_lst **lst)
{
	t_lst	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_list_delone((*lst));
		(*lst) = tmp;
	}
}

t_lst	*ft_list_swap(t_lst *list_1, t_lst *list_2)
{
	t_lst	*tmp;

	if (list_1 == NULL || list_2 == NULL)
		return (NULL);
	tmp = list_1->next;
	list_1->next = list_2->next;
	list_2->next = list_1;
	return (list_2);
}

int		ft_list_size(t_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
