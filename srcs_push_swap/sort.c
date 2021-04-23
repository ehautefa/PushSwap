/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:09:16 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 11:42:34 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*ft_sort_by_insertion_tab(int *tab, int size)
{
	int i;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
	return (tab);
}

int		ft_find_median(t_lst *lst, int *med)
{
	int		size;
	int		*tab;
	int		i;

	i = -1;
	size = ft_list_size(lst);
	tab = malloc(size * sizeof(int));
	if (tab == NULL)
		return (-1);
	while (lst)
	{
		tab[++i] = lst->num;
		lst = lst->next;
	}
	tab = ft_sort_by_insertion_tab(tab, size);
	*med = tab[(int)(size / 2)];
	free(tab);
	return (0);
}
