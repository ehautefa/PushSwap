/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retur_to_a_100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:39:40 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 16:57:23 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_adjust_order_bloc(t_env *env, int *tab, int i)
{
	int		j;
	int		up;
	int		down;

	j = -1;
	while (++j < env->size_bloc[i])
	{
		while (env->b->num != tab[j])
		{
			down = find_num_of_rev_rot(env->b, tab[j],
				ft_list_size(env->b)) + 1;
			up = find_num_of_rot(env->b, tab[j]) + 1;
			if (up == 1)
				ft_s(env, 'b');
			else if (up <= down)
				while (--up > 0)
					ft_r(env, 'b');
			else
				while (--down > 0)
					ft_rr(env, 'b');
		}
		ft_p(env, 'a');
	}
}

void	sort_bloc(t_env *env, int i)
{
	int		*tab;
	int		j;
	t_lst	*lst;

	j = -1;
	lst = env->b;
	tab = malloc(env->size_bloc[i] * sizeof(int));
	if (tab == NULL)
		ft_print_error_and_free(env, 1);
	while (++j < env->size_bloc[i])
	{
		tab[j] = lst->num;
		lst = lst->next;
	}
	tab = ft_sort_by_insertion_tab(tab, env->size_bloc[i]);
	ft_adjust_order_bloc(env, tab, i);
	free(tab);
}

int		find_num_of_rev_rot(t_lst *lst, int to_find, int size)
{
	int		num;
	t_lst	*last;
	int		i;

	i = size;
	num = 1;
	last = find_i_element_list(lst, i);
	while (last)
	{
		if (last->num == to_find)
			return (num);
		last = find_i_element_list(lst, --i);
		num++;
	}
	return (num);
}

int		find_num_of_rot(t_lst *lst, int to_find)
{
	int		num;

	num = 0;
	while (lst)
	{
		if (lst->num == to_find)
			return (num);
		lst = lst->next;
		num++;
	}
	return (num);
}
