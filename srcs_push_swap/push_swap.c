/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:43:25 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/22 16:11:27 by ehautefa         ###   ########.fr       */
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
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

void	ft_print_error(int *tab)
{
	if (tab)
		free(tab);
	tab = NULL;
	write(2, "Error\n", 6);
	exit(1);
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
	int		*tab;
	int		i;

	i = -1;
	tab = NULL;
	if (ac < 2)
		return (0);
	if (ft_check_error(ac, av) != 0)
		return (-1);
	if (!(tab = malloc(ac * sizeof(int))))
		ft_print_error(tab);
	while (++i < ac - 1)
	{
		tab[i] = ft_atoi(av[i + 1]);
		if (tab[i] > 0 && av[i + 1][0] == '-')
			ft_print_error(tab);
		if (tab[i] < 0 && av[i + 1][0] != '-')
			ft_print_error(tab);
		printf("tab[i] : %d\n", tab[i]);
	}
}
