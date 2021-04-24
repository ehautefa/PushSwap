/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:51:03 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/24 12:30:07 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ft_s(t_env *env, char c)
{
	t_lst	*lst;

	if (c == 'a')
		lst = env->a;
	if (c == 'b')
		lst = env->b;
	if (lst == NULL || lst->next == NULL)
		return ;
	if (!(lst = ft_list_swap(lst, lst->next)))
		ft_print_error_and_free(env, 1);
	if (c == 'a')
		env->a = lst;
	if (c == 'b')
		env->b = lst;
}

void	ft_p(t_env *env, char c)
{
	t_lst *tmp;

	if (c == 'a')
	{
		tmp = env->b;
		env->b = env->b->next;
		ft_list_add_front(&env->a, tmp);
	}
	if (c == 'b')
	{
		tmp = env->a;
		env->a = env->a->next;
		ft_list_add_front(&env->b, tmp);
	}
}

void	ft_r(t_env *env, char c)
{
	t_lst	*tmp;
	t_lst	*last;

	if (c == 'a')
	{
		tmp = env->a;
		env->a = env->a->next;
		tmp->next = NULL;
		last = ft_list_last(env->a);
	}
	if (c == 'b')
	{
		tmp = env->b;
		env->b = env->b->next;
		tmp->next = NULL;
		last = ft_list_last(env->b);
	}
	last->next = tmp;
}

void	ft_rr(t_env *env, char c)
{
	t_lst	*tmp;
	t_lst	*last;

	if (c == 'a')
	{
		tmp = ft_list_last2(env->a);
		last = tmp->next;
		tmp->next = NULL;
		last->next = env->a;
		env->a = last;
	}
	if (c == 'b')
	{
		tmp = ft_list_last2(env->b);
		last = tmp->next;
		tmp->next = NULL;
		last->next = env->b;
		env->b = last;
	}
}
