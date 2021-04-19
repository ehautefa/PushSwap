/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:21 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/19 15:35:46 by ehautefa         ###   ########.fr       */
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
	if (i < (int)ft_strlen(str) || i > 11)
	{
		write (2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int		ft_check_error(int ac, char **av)
{
	int ret;

	ret = 0;
	while (--ac > 0 && ret == 0)
		ret = ft_check_integer(av[ac]);
	if (ret == -1)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_check_error(ac, av) != 0)
		return (-1);
}
