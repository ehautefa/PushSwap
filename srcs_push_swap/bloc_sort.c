/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:37:13 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 15:31:12 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_find_low_value(t_env *env, int med, int *size)
{
	t_lst	*tmp;
	
	if (env->a->num > med)
	{
		tmp = ft_list_last(env->a);
		if (tmp->num <= med)
			ft_rr(env, 'a');
		else
		{
			ft_r(env, 'a');
			while (env->a->num < med)
			 	ft_r(env, 'a');
		}
	}
	ft_p(env, 'b');
	*size -= 1;
}

void	ft_adjust_a_heap(t_env *env)
{
	if (ft_list_size(env->a) == 2)
	{
		if (env->a->num > env->a->next->num)
			ft_s(env, 'a');
	}
}

int		find_size_length_bloc(int	size)
{
	int		i;

	i = 0;
	while (size > 2)
	{
		i++;
		size /= 2;
	}
	return (i);
}

void	ft_adjust_rotation(t_env *env, int nb_r)
{
	while (nb_r > 0)
	{
		nb_r--;
		ft_rr(env, 'b');
	}
}

void	ft_adjust_order_bloc(t_env *env, int *tab, int i)
{
	int		j;
	int		nb_r;

	j = -1;
	nb_r = 0;
	j = -1;
	while (++j < env->size_bloc[i])
	{
		while (env->b->num != tab[j])
		{
			if (nb_r < env->size_bloc[i])
			{
				ft_r(env, 'b');
				nb_r++;
			}
			else
			{
				ft_rr(env, 'b');
				nb_r--;
			}
		}
		ft_p(env, 'a');
	}
	if (ft_list_size(env->b) > 0)
		ft_adjust_rotation(env, nb_r);
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

	i = 0;
	while (i < env->nb_bloc)
	{
		sort_bloc(env, i);
		i++;
	}
}

void	cut_heap(t_env *env)
{
	int		size;
	int		med;
	int		lim;
	int		i;

	size = env->size;
	env->nb_bloc = find_size_length_bloc(size);
	env->size_bloc = malloc(env->nb_bloc * sizeof(int));
	if (env->size_bloc == NULL)
		ft_print_error_and_free(env, 1);
	i = -1;
	while (size > 2)
	{
		if (ft_find_median(env->a, &med) == -1)
			ft_print_error_and_free(env, 1);
		printf("MED : %d\n", med);
		lim = size / 2;
		env->size_bloc[++i] = size - lim;
		while (size > lim)
			ft_find_low_value(env, med, &size);
		ft_print_env(env);
	}
	ft_adjust_a_heap(env);
	ft_retur_to_b_heap(env);
	ft_print_env(env);
}

