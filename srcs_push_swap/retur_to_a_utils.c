/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retur_to_a_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:18:14 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 16:54:32 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_adjust_rotation(t_env *env, int *nb_r, int j, char c)
{
	int	size;
	t_lst	*lst;

	lst = env->a;
	if (c == 'b')
		lst= env->b;
	size = ft_list_size(lst);
	if (size > env->size_bloc[env->nb_bloc - 1])
	{
		while (*nb_r - j > 0)
		{
			*nb_r -= 1;
			ft_rr(env, c);
		}
	}
}

int		list_is_sort(t_env *env, char c, int size)
{
	t_lst	*lst;
	int		i;

	i = -1;
	lst = env->a;
	if (c == 'b')
		lst = env->b;
	while (lst && lst->next && ++i < size)
	{
		if ((c == 'b' && lst->num < lst->next->num) ||
			(c == 'a' && lst->num > lst->next->num))
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	opposite(char c)
{
	if (c == 'a')
		return ('b');
	if (c == 'b')
		return ('a');
	return (-1);
}

void	ft_repeat(int size, t_env *env, char c)
{
	if (list_is_sort(env, opposite(c), size) == 0)
	{
		cut_bloc(env, opposite(c), size);
		cut_bloc(env, c, size);
	}
}
