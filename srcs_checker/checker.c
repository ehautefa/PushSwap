/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:21 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/20 11:09:47 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		ft_check_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < (int)ft_strlen(str) || i > 11)
		return (-1);
	return (0);
}

void	ft_print_error_and_free(t_env *env)
{
	if (env->tab_a)
		free(env->tab_a);
	env->tab_a = NULL;
	if (env->tab_b)
		free(env->tab_b);
	env->tab_b = NULL;
	if (env->arg)
		free(env->arg);
	env->arg = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

int		ft_checker_error(int ac, char **av, t_env *env)
{
	int ret;

	ret = 0;
	env->size = 0;
	while (++(env->size) < ac && ret == 0)
		ret = ft_check_integer(av[env->size]);
	env->size -= 1;
	printf("%d\n", env->size);
	return (0);
}

void	ft_init_tab(char **av, t_env *env)
{
	int		i;

	i = -1;
	if (!(env->tab_a = malloc(env->size * sizeof(int))))
		ft_print_error_and_free(env);
	if (!(env->tab_b = malloc(env->size * sizeof(int))))
		ft_print_error_and_free(env);
	while (++i <  env->size)
	{
		env->tab_a[i] = ft_atoi(av[i + 1]);
		if (env->tab_a[i] > 0 && av[i + 1][0] == '-')
			ft_print_error_and_free(env);
		if (env->tab_a[i] < 0 && av[i + 1][0] != '-')
			ft_print_error_and_free(env);
		printf("env->tab_a[i] : %d\n", env->tab_a[i]);
	}
}

void	ft_print_env(t_env *env)
{
	int	i;

	i = -1;
	while (env->tab_a[++i])
		printf("tab_a[%d] : |%d|\n", i, env->tab_a[i]);
	i = -1;
	while (env->tab_b[++i])
		printf("tab_b[%d] : |%d|\n", i, env->tab_b[i]);
	i = -1;
	while (env->arg[++i])
		printf("arg[%d] : |%s|\n", i, env->arg[i]);
	printf("size : |%d|\n", env->size);
	printf("nb_arg : |%d|\n", env->nb_arg);
}
void	ft_init_arg(int	ac, char **av, t_env *env)
{
	int		i;

	(void)ac;
	i = env->size;
	env->arg = ft_split_str(av[i], "\\n");
	ft_print_env(env);
}

int		main(int ac, char **av)
{
	t_env	env;
	
	env.tab_a = NULL;
	env.tab_b = NULL;
	env.arg = NULL;
	if (ac < 2)
		return (0);
	if (ft_checker_error(ac, av, &env) != 0)
		return (-1);
	ft_init_tab(av, &env);
	ft_init_arg(ac, av, &env);
	return (0);
}