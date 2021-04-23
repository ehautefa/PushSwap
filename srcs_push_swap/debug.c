/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:38 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 10:48:23 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_list_print(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("lst[%d] : %d\n", i, lst->num);
		lst = lst->next;
		i++;
	}
}

void	ft_print_env(t_env *env)
{
	printf("\na:\n");
	if (env->a)
		ft_list_print(env->a);
	printf("\nb:\n");
	if (env->b)
		ft_list_print(env->b);
	printf("\n");
	printf("size : |%d|\n", env->size);
}
