/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:37:13 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 16:59:20 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_find_low_value(t_env *env, float med, int *size)
{
	int		down;
	int		up;

	if ((float)env->a->num >= med)
	{
		down = find_number_of_rev_rot(env->a, med, *size, 'a') + 1;
		up = find_number_of_rot(env->a, med, 'a') + 1;
		if (up == 1)
			ft_s(env, 'a');
		else if (up <= down)
			while (--up > 0)
				ft_r(env, 'a');
		else
			while (--down > 0)
				ft_rr(env, 'a');
	}
	ft_p(env, 'b');
	*size -= 1;
}

int		find_size_bloc(int size, int lim)
{
	int		i;

	i = 0;
	while (size > lim)
	{
		i++;
		size += size % 2;
		size /= 2;
	}
	return (i);
}

void	cut_heap(t_env *env)
{
	int		size;
	float	med;
	int		lim;
	int		i;

	size = env->size;
	env->nb_bloc = find_size_bloc(size, 3);
	env->size_bloc = malloc(env->nb_bloc * sizeof(int));
	if (env->size_bloc == NULL)
		ft_print_error_and_free(env, 1);
	i = -1;
	while (size > 3)
	{
		if (ft_find_median(env, size, &med, 'a') == -1)
			ft_print_error_and_free(env, 1);
		lim = size / 2 + size % 2;
		env->size_bloc[++i] = size - lim;
		while (size > lim)
			ft_find_low_value(env, med, &size);
	}
	sort_3(env);
	ft_retur_to_b_heap(env);
}
