/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reur_to_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:18:14 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/27 13:20:18 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_num_of_rev_rot(t_lst *lst, int to_find, int size)
{
	int		num;
	t_lst	*last;
	int		i;

	i = size;
	num = 1;
	last = find_i_element_list(lst, i);
	while (last)
	{
		if (last->num == to_find)
			return (num);
		last = find_i_element_list(lst, --i);
		num++;
	}
	return (num);
}

int		find_num_of_rot(t_lst *lst, int to_find)
{
	int		num;

	num = 0;
	while (lst)
	{
		if (lst->num == to_find)
			return (num);
		lst = lst->next;
		num++;
	}
	return (num);
}