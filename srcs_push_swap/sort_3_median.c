/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:09:16 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 17:56:20 by ehautefa         ###   ########.fr       */
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
	while (i < size - 1 && lst)
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
	tab = NULL;
	return (0);
}

int		find_biggest_index(t_lst *lst)
{
	t_lst	*last;
	t_lst	*mid;

	if (!lst->next)
		return (2);
	if (!lst->next->next)
		return (2);
	mid = lst->next;
	last = mid->next;
	if (lst->num > mid->num && lst->num > last->num)
		return (0);
	if (mid->num > lst->num && mid->num > last->num)
		return (1);
	if (last->num > lst->num && last->num > mid->num)
		return (2);
	return (-1);
}

void	sort_3(t_env *env)
{
	int	index;

	index = find_biggest_index(env->a);
	if (index == 1)
		ft_rr(env, 'a');
	if (index == 0)
		ft_r(env, 'a');
	if (index == 3)
		return ;
	if (env->a->num > env->a->next->num)
		ft_s(env, 'a');
}
