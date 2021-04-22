/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:15:23 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/22 16:11:17 by ehautefa         ###   ########.fr       */
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
	if (i == 0)
		return (1);
	if (i < (int)ft_strlen(str))
		return (-1);
	return (0);
}

void	ft_print_error_and_free(t_env *env, int error)
{
	int		i;

	i = -1;
	if (env->a)
		ft_list_clear(&env->a);
	env->a = NULL;
	if (env->b)
		ft_list_clear(&env->b);
	env->b = NULL;
	while (++i < env->nb_arg)
		free(env->arg[i]);
	env->arg = NULL;
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

int		ft_checker_error(int ac, char **av, t_env *env)
{
	int ret;

	ret = 0;
	env->size = 0;
	while (++(env->size) < ac && ret == 0)
		ret = ft_check_integer(av[env->size]);
	env->size -= 1;
	if (ac != env->size + 1)
		ft_print_error_and_free(env, 1);
	if (ret == 1)
		env->size -= 1;
	return (0);
}

void	ft_check_arg_error(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->nb_arg)
	{
		if (ft_strcmp(env->arg[i], "sa") == 0)
			ft_s(env, 'a');
		else if (ft_strcmp(env->arg[i], "sb") == 0)
			ft_s(env, 'b');
		else if (ft_strcmp(env->arg[i], "ss") == 0)
		{
			ft_s(env, 'a');
			ft_s(env, 'b');
		}
		else if (ft_strcmp(env->arg[i], "pa") == 0)
			ft_p(env, 'a');
		else if (ft_strcmp(env->arg[i], "pb") == 0)
			ft_p(env, 'b');
		else if (ft_r_arg(env, i) == -1)
			ft_print_error_and_free(env, 1);
	}
}

int		ft_r_arg(t_env *env, int i)
{
	if (ft_strcmp(env->arg[i], "ra") == 0)
		ft_r(env, 'a');
	else if (ft_strcmp(env->arg[i], "rb") == 0)
		ft_r(env, 'b');
	else if (ft_strcmp(env->arg[i], "rr") == 0)
	{
		ft_r(env, 'a');
		ft_r(env, 'b');
	}
	else if (ft_strcmp(env->arg[i], "rra") == 0)
		ft_rr(env, 'a');
	else if (ft_strcmp(env->arg[i], "rrb") == 0)
		ft_rr(env, 'b');
	else if (ft_strcmp(env->arg[i], "rrr") == 0)
	{
		ft_rr(env, 'a');
		ft_rr(env, 'b');
	}
	else
		return (-1);
	return (0);
}
