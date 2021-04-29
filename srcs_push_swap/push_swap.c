/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:43:25 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 16:40:00 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_duplicates(t_env *env)
{
	t_lst	*lst1;
	t_lst	*lst2;

	lst1 = env->a;
	while (lst1)
	{
		lst2 = lst1->next;
		while (lst2)
		{
			if (lst1->num == lst2->num)
				ft_print_error_and_free(env, 1);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
}

void	ft_init_tab(char **av, t_env *env)
{
	int		i;
	int		nb;
	t_lst	*list;

	i = 0;
	nb = ft_atoi(av[i + 1]);
	if (nb > 0 && av[i + 1][0] == '-')
		ft_print_error_and_free(env, 1);
	if (nb < 0 && av[i + 1][0] != '-')
		ft_print_error_and_free(env, 1);
	list = ft_list_new(nb);
	if (list == NULL)
		ft_print_error_and_free(env, 0);
	while (++i < env->size)
	{
		nb = ft_atoi(av[i + 1]);
		if (nb > 0 && av[i + 1][0] == '-')
			ft_print_error_and_free(env, 0);
		if (nb < 0 && av[i + 1][0] != '-')
			ft_print_error_and_free(env, 0);
		if (ft_list_add_back(&list, ft_list_new(nb)) == -1)
			ft_print_error_and_free(env, 0);
	}
	env->a = list;
	ft_check_duplicates(env);
}

int		main(int ac, char **av)
{
	t_env	env;

	env.a = NULL;
	env.b = NULL;
	env.size_bloc = NULL;
	if (ac < 2)
		return (0);
	if (ft_checker_error(ac, av, &env) == -1)
		ft_print_error_and_free(&env, 1);
	ft_init_tab(av, &env);
	if (list_is_sort(&env, 'a', env.size) == 1)
		ft_print_error_and_free(&env, 0);
	cut_heap(&env);
	ft_print_error_and_free(&env, 0);
	return (0);
}
