/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bloc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:55:42 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/28 14:34:21 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*find_i_element_list(t_lst *lst, int i)
{
	if (lst == NULL)
		return (NULL);
	while (lst && i > 1)
	{
		i--;
		lst = lst->next;
	}
	return (lst);
}

int		find_number_of_rev_rot(t_lst *lst, float med, int size, char c)
{
	int		num;
	t_lst	*last;
	int		i;

	i = size;
	num = 1;
	last = find_i_element_list(lst, i);
	while (last)
	{
		if ((c == 'a' && (float)last->num < med) ||
			(c == 'b' && (float)last->num > med))
			return (num);
		last = find_i_element_list(lst, --i);
		num++;
	}
	return (num);
}

int		find_number_of_rot(t_lst *lst, float med, char c)
{
	int		num;

	num = 0;
	while (lst)
	{
		if ((c == 'a' && (float)lst->num < med) ||
			(c == 'b' && (float)lst->num > med))
			return (num);
		lst = lst->next;
		num++;
	}
	return (num);
}
