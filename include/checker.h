/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:45:10 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 17:44:45 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H
#include "lst_utils.h"

typedef struct s_env
{
	t_lst *a;
	t_lst *b;
	int size;
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

#endif
