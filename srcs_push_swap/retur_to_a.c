/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retur_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:39:40 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/27 13:27:08 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_adjust_rotation(t_env *env, int *nb_r, int j)
{
	int	size;

	size = ft_list_size(env->b);
	if (size > env->size_bloc[env->nb_bloc - 1])
	{
		while (*nb_r - j > 0)
		{
			*nb_r -= 1;
			ft_rr(env, 'b');
		}
	}
}

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

void	ft_retur_to_b_heap(t_env *env)
{
	int		i;

	i = env->nb_bloc - 1;
	while (i >= 0)
	{
		sort_bloc(env, i);
		i--;
	}
}
