/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retur_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:39:40 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/28 14:47:59 by ehautefa         ###   ########.fr       */
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

void	ft_find_value(t_env *env, float med, int *size, char c)
{
	int		down;
	int		up;
	t_lst	*lst;

	lst = env->a;
	if (c == 'b')
		lst = env->b;
	if ((float)lst->num >= med)
	{
		down = find_number_of_rev_rot(lst, med, *size, c) + ft_list_size(lst) - *size;
		up = find_number_of_rot(lst, med, c) + 1;
		if (up == 1)
			ft_s(env, c);
		else if (up <= down)
			while (--up > 0)
				ft_r(env, c);
		else
			while (--down > 0)
				ft_rr(env, c);
	}
	c = c == 'a' ? 'b' : 'a';
	ft_p(env, c);
	*size -= 1;
}

void	sort_2(t_env *env, char c)
{
	if (c == 'a')
	{
		if (env->a->num > env->a->next->num)
			ft_s(env, c);
	}
	if (c == 'b')
	{
		if (env->b->num < env->b->next->num)
			ft_s(env, c);
	}
	c = c == 'a' ? 'b' : 'a';
	ft_p(env, c);
	ft_p(env, c);
}

int		ft_transfer_bloc(t_env *env, int size, char c)
{
	float	med;
	int		lim;
	int		i;
	int		nb_bloc;
	int		*size_bloc;

	nb_bloc = find_size_length_bloc(size);
	size_bloc = malloc(nb_bloc * sizeof(int));
	if (size_bloc == NULL)
		ft_print_error_and_free(env, 1);
	i = -1;
	while (size > 2)
	{
		if (ft_find_median(env, size, &med, c) == -1)
			ft_print_error_and_free(env, 1);
		lim = size / 2 + size % 2;
		size_bloc[++i] = size - lim;
		while (size > lim)
			ft_find_value(env, med, &size, c);
	}
	sort_2(env, c);
	return(size_bloc[i]);
}

void	sort_bloc(t_env *env, int i)
{
	char	c;
	int		size;
	int		j;

	size = env->size_bloc[i];
	j = 0;
	while (size > 0)
	{
		c = 'a';
		if (j % 2 == 0)
			c = 'b';
		size = ft_transfer_bloc(env, size, c);
		j++;
	}
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
