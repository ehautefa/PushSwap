/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:37:13 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 13:41:51 by ehautefa         ###   ########.fr       */
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

void	cut_heap(t_env *env)
{
	int		size;
	int		med;
	int		lim;

	size = env->size;
	while (size > 2)
	{
		if (ft_find_median(env->a, &med) == -1)
			ft_print_error_and_free(env, 1);
		printf("MED : %d\n", med);
		lim = size / 2;
		while (size > lim)
		{
			ft_find_low_value(env, med, &size);
		}
		ft_print_env(env);
	}
	ft_adjust_a_heap(env);
	ft_print_env(env);
}

