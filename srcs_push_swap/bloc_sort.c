/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:37:13 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/27 17:16:34 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_position(t_lst *lst, int a)
{
	int		i;
	int		first_smallest;
	int		first_biggest;
	int		pos;
	int		pos2;

	i = 0;
	if (!lst)
		return (0);
	first_smallest = -2147483648;
	first_biggest = 2147483647;
	pos = 0;
	while (lst)
	{
		if (lst->num > first_smallest && lst->num < a)
		{
			first_smallest = lst->num;
			pos = i;
		}
		if (lst->num < first_biggest && lst->num > a)
		{
			first_biggest = lst->num;
			pos2 = i;
		}
		i++;
		lst = lst->next;
	}
	if (first_smallest == -2147483648 && pos == 0)
		pos = pos2 + 1;
	return (pos);
}

void	ft_place_value_in_b(t_env *env)
{
	int	size;
	int	pos;

	size = ft_list_size(env->b);
	pos = find_position(env->b, env->a->num);
	if (pos > size / 2)
	{
		while (size - pos > 0)
		{
			ft_rr(env, 'b');
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ft_r(env, 'b');
			pos--;
		}
	}
	ft_p(env, 'b');
}

void	ft_find_low_value(t_env *env, float med, int *size)
{
	int		down;
	int		up;

	if ((float)env->a->num >= med)
	{
		down = find_number_of_rev_rot(env->a, med, *size) + 1;
		up = find_number_of_rot(env->a, med) + 1;
		if (up == 1)
			ft_s(env, 'a');
		else if (up <= down)
			while (--up > 0)
				ft_r(env, 'a');
		else
			while (--down > 0)
				ft_rr(env, 'a');
	}
	ft_place_value_in_b(env);
	*size -= 1;
}

int		find_size_length_bloc(int size)
{
	int		i;

	i = 0;
	while (size > 3)
	{
		i++;
		size += size % 2;
		size /= 2;
	}
	return (i);
}

void	ft_retur_to_a(t_env *env)
{
	int		pos_smallest;
	int		size;

	size = env->size - ft_list_size(env->a);
	pos_smallest = find_position(env->b, -2147483648);
	if (pos_smallest > size / 2)
	{
		while (size - pos_smallest > 0)
		{
			ft_rr(env, 'b');
			pos_smallest++;
		}
	}
	else
	{
		while (pos_smallest > 0)
		{
			ft_r(env, 'b');
			pos_smallest--;
		}
	}
	while (env->b)
		ft_p(env, 'a');
}

void	cut_heap(t_env *env)
{
	int		size;
	float	med;
	int		lim;
	int		i;

	size = env->size;
	env->nb_bloc = find_size_length_bloc(size);
	env->size_bloc = malloc(env->nb_bloc * sizeof(int));
	if (env->size_bloc == NULL)
		ft_print_error_and_free(env, 1);
	i = -1;
	while (size > 3)
	{
		if (ft_find_median(env->a, &med) == -1)
			ft_print_error_and_free(env, 1);
		lim = size / 2 + size % 2;
		env->size_bloc[++i] = size - lim;
		while (size > lim)
			ft_find_low_value(env, med, &size);
	}
	sort_3(env);
	ft_retur_to_a(env);
}
