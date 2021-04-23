/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:15:23 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/23 10:47:21 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_check_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < (int)ft_strlen(str) || i == 0)
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
	if (env->size != ac - 1 || ret == -1)
		return (-1);
	return (0);
}
