/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:21 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/22 13:41:14 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

void	ft_init_arg(int ac, char **av, t_env *env)
{
	int		i;

	i = 0;
	if (av[ac - 1][i] == '-')
		i++;
	while (av[ac - 1][i] >= '0' && av[ac - 1][i] <= '9')
		i++;
	env->arg = ft_split_str(&av[ac - 1][i], "\\n");
	env->nb_arg = ft_strslen(env->arg);
}

void	ft_check_sort(t_env *env)
{
	t_lst	*lst;
	int		tmp;
	int		i;

	lst = env->a;
	tmp = lst->num;
	i = 0;
	while (lst)
	{
		if (lst->num < tmp)
		{
			write(1, "KO\n", 3);
			ft_print_error_and_free(env, 0);
		}
		tmp = lst->num;
		lst = lst->next;
		i++;
	}
	if (i != env->size)
	{
		write(1, "KO\n", 3);
		ft_print_error_and_free(env, 0);
	}
	write(1, "OK\n", 3);
}

int		main(int ac, char **av)
{
	t_env	env;

	env.a = NULL;
	env.b = NULL;
	env.arg = NULL;
	if (ac < 2)
		return (0);
	if (ft_checker_error(ac, av, &env) != 0)
		return (-1);
	ft_init_tab(av, &env);
	ft_init_arg(ac, av, &env);
	ft_check_arg_error(&env);
	ft_check_sort(&env);
	ft_print_error_and_free(&env, 0);
	return (0);
}
