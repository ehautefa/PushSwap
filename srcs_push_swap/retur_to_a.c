/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retur_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:39:40 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 17:05:41 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_find_value(t_env *env, float med, int *size, char c)
{
	int		down;
	int		up;
	t_lst	*lst;
	int		nb_r;

	nb_r = 0;
	lst = env->a;
	if (c == 'b')
		lst = env->b;
	if ((c == 'a' && (float)lst->num >= med) || (c == 'b' && (float)lst->num <= med))
	{
		down = find_number_of_rev_rot(lst, med, *size, c) + ft_list_size(lst) - *size + 1;
		up = find_number_of_rot(lst, med, c) + 1;
		if (up == 1 || up == 2)
			ft_s(env, c);
		else if (up <= down)
			while (--up > 0)
			{
				ft_r(env, c);
				nb_r++;
			}
		else
			while (--down > 0)
			{
				ft_rr(env, c);
				nb_r--;
			}
	}
	c = c == 'a' ? 'b' : 'a';
	ft_p(env, c);
	*size -= 1;
	return (nb_r);
}

void	replace_last_bloc(t_env *env, char c, int size)
{
	t_lst	*lst;

	lst = env->a;
	if (c == 'b')
		lst = env->b;
	if ((c == 'b' && lst->num < lst->next->num) ||
			(c == 'a' && lst->num > lst->next->num))
		ft_s(env, c);
	while (size-- > 0)
		ft_p(env, opposite(c));
}

int		*deplace_bloc(int size, t_env *env, char c, int *size_bloc)
{
	int		i;
	float	med;
	int		lim;
	int		nb_r;

	i = -1;
	nb_r = 0;
	while (size > 2)
	{
		if (ft_find_median(env, size, &med, c) == -1)
			ft_print_error_and_free(env, 1);
		lim = size / 2 + size % 2;
		size_bloc[++i] = size - lim;
		while (size > lim)
			nb_r += ft_find_value(env, med, &size, c);
		ft_adjust_rotation(env, &nb_r, 0, c);
		ft_repeat(size_bloc[i], env, c);
	}
	if ((c == 'b' && env->a->num > env->a->next->num) ||
			(c == 'a' && env->b->num < env->b->next->num))
		ft_s(env, opposite(c));
	replace_last_bloc(env, c, size);
	return (size_bloc);
}

void	cut_bloc(t_env *env, char c, int size)
{
	int 	nb_bloc;
	t_lst	*lst;
	int		*size_bloc;

	lst = env->a;
	if (c == 'b')
		lst = env->b;
	nb_bloc = find_size_bloc(size, 1);
	if (nb_bloc < 2)
		replace_last_bloc(env, c, size);
	else
	{
		if (!(size_bloc = malloc(nb_bloc * sizeof(int))))
			ft_print_error_and_free(env, 1);
		size_bloc = deplace_bloc(size, env, c, size_bloc);
		if (size_bloc)
			free(size_bloc);
		size_bloc = NULL;
	}
}

void	ft_retur_to_b_heap(t_env *env)
{
	int		i;

	i = env->nb_bloc - 1;
	while (i >= 0)
	{
		if (env->size < 250)
			sort_bloc(env, i);
		else
			cut_bloc(env, 'b', env->size_bloc[i]);
		i--;
	}
}
