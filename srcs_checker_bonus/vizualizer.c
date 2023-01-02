/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:17:30 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 17:53:02 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void ft_find_range(t_env *env, t_lst *lst)
{
	int max;
	int min;

	max = -2147483648;
	min = 2147483647;
	if (!lst)
		env->range = 0;
	while (lst)
	{
		if (lst->num > max)
			max = lst->num;
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	env->range = max > -min ? max : min;
}

void ft_display_number(int range, int num)
{
	int i;
	int size;

	i = 0;
	printf("| %9d |", num);
	size = ((int)(float)(SIZE_DISPLAY * num) / range);
	size = size < 0 ? -size : size;
	while (size - i > 0)
	{
		printf("-");
		i++;
	}
	while (i < SIZE_DISPLAY)
	{
		printf(" ");
		i++;
	}
	printf("\t");
}

void ft_wait(void)
{
	long long i;

	i = 0;
	while (i < 9999999)
		i++;
}

void ft_clear_window(void)
{
	int i;

	i = -1;
	system("clear");
	while (++i < 40 + 2 * SIZE_DISPLAY)
		printf("/");
	printf("\n");
}

void ft_print_stack(t_lst *a, t_lst *b, int range)
{
	ft_clear_window();
	while (a && b)
	{
		ft_display_number(range, a->num);
		ft_display_number(range, b->num);
		printf("\n");
		a = a->next;
		b = b->next;
	}
	while (a)
	{
		ft_display_number(range, a->num);
		printf("\n");
		a = a->next;
	}
	while (b)
	{
		ft_display_number(range, 0);
		ft_display_number(range, b->num);
		printf("\n");
		b = b->next;
	}
	printf("\n");
	ft_wait();
}
