/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:21 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/28 11:56:13 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void ft_check_duplicates(t_env *env)
{
	t_lst *lst1;
	t_lst *lst2;

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

void ft_init_tab(char **av, t_env *env)
{
	int i;
	int nb;
	t_lst *list;

	i = env->mk_v == 1 ? 1 : 0;
	nb = ft_atoi(av[i + 1]);
	if (nb > 0 && av[i + 1][0] == '-')
		ft_print_error_and_free(env, 1);
	if (nb < 0 && av[i + 1][0] != '-')
		ft_print_error_and_free(env, 1);
	list = ft_list_new(nb);
	if (list == NULL)
		ft_print_error_and_free(env, 1);
	while (++i < env->size)
	{
		nb = ft_atoi(av[i + 1]);
		if (nb > 0 && av[i + 1][0] == '-')
			ft_print_error_and_free(env, 1);
		if (nb < 0 && av[i + 1][0] != '-')
			ft_print_error_and_free(env, 1);
		if (ft_list_add_back(&list, ft_list_new(nb)) == -1)
			ft_print_error_and_free(env, 1);
	}
	env->a = list;
	ft_check_duplicates(env);
}

void ft_init_arg(t_env *env)
{
	int i;
	int ret;
	char *line;

	i = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		ft_check_arg_error(env, line);
		if (env->mk_v == 1)
			ft_print_stack(env->a, env->b, env->range);
		free(line);
	}
}

void ft_check_sort(t_env *env)
{
	t_lst *lst;
	int tmp;
	int i;

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
	if (i != env->size - env->mk_v || ft_list_size(env->b) != 0)
	{
		write(1, "KO\n", 3);
		ft_print_error_and_free(env, 0);
	}
	write(1, "OK\n", 3);
}

int main(int ac, char **av)
{
	t_env env;

	env.a = NULL;
	env.b = NULL;
	env.mk_v = 0;
	if (ac < 2)
		return (0);
	if (ft_checker_error(ac, av, &env) != 0)
		return (-1);
	ft_init_tab(av, &env);
	ft_find_range(&env, env.a);
	if (env.mk_v == 1)
		ft_print_stack(env.a, env.b, env.range);
	ft_init_arg(&env);
	ft_check_sort(&env);
	ft_print_error_and_free(&env, 0);
	return (0);
}
