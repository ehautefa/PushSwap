/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisehautefaye <elisehautefaye@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:45:10 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/27 22:02:47 by elisehautef      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H
#include "lst_utils.h"

#define SIZE_DISPLAY 50

typedef struct s_env
{
	t_lst *a;
	t_lst *b;
	int size;
	int range;
	int mk_v;
} t_env;

/*
**  error.c
*/
int ft_check_integer(char *str);
void ft_print_error_and_free(t_env *env, int error);
int ft_checker_error(int ac, char **av, t_env *env);
void ft_check_arg_error(t_env *env, char *arg);
int ft_r_arg(t_env *env, char *arg);

/*
**  checker.c
*/
void ft_check_duplicates(t_env *env);
void ft_init_tab(char **av, t_env *env);
void ft_init_arg(t_env *env);
void ft_check_sort(t_env *env);

/*
**  ft_arg.c
*/
void ft_s(t_env *env, char c);
void ft_p(t_env *env, char c);
void ft_r(t_env *env, char c);
void ft_rr(t_env *env, char c);

/*
**  vizualizer.c
*/
void ft_find_range(t_env *env, t_lst *lst);
void ft_display_number(int range, int num);
void ft_print_stack(t_lst *a, t_lst *b, int range);
void ft_wait(void);
void ft_clear_window(void);

#endif
