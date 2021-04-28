/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:09:16 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/28 13:57:38 by ehautefa         ###   ########.fr       */
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

int		*ft_reversort_by_insertion_tab(int *tab, int size)
{
	int i;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
	return (tab);
}

int		ft_find_median(t_env *env, int size, float *med, char c)
{
	int		*tab;
	int		i;
	t_lst	*lst;

	lst = env->a;
	if (c == 'b')
		lst = env->b;
	i = -1;
	tab = malloc(size * sizeof(int));
	if (tab == NULL)
		return (-1);
	while (i < size && lst)
	{
		tab[++i] = lst->num;
		lst = lst->next;
	}
	tab = ft_sort_by_insertion_tab(tab, size);
	if (size % 2 == 0)
		*med = ((float)((tab[(size - 1) / 2] + tab[(size + 1) / 2]))) / 2;
	else
		*med = tab[(int)(size / 2)];
	free(tab);
	return (0);
}
