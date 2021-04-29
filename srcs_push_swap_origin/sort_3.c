/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:37:54 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/26 17:10:59 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
