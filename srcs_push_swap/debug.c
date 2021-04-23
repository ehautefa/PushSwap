/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:38 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 16:36:47 by ehautefa         ###   ########.fr       */
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
	int		i;

	i = -1;
	printf("//////////////////////////////////////////");
	printf("\na:\n");
	if (env->a)
		ft_list_print(env->a);
	printf("\nb:\n");
	if (env->b)
		ft_list_print(env->b);
	printf("\nsize_bloc : \n");
	while (env->size_bloc && ++i < env->nb_bloc)
		printf("env->size_bloc[%d] : %d\n", i, env->size_bloc[i]);
	printf("nb_bloc : %d\n", env->nb_bloc);
	printf("size : |%d|\n", env->size);
}
