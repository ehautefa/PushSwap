/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:45:10 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/24 12:29:03 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_lst
{
	int				num;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_env
{
	t_lst	*a;
	t_lst	*b;
	int		size;
}				t_env;

// error.c
int				ft_check_integer(char *str);
void			ft_print_error_and_free(t_env *env, int error);
int				ft_checker_error(int ac, char **av, t_env *env);
void			ft_check_arg_error(t_env *env, char *arg);
int				ft_r_arg(t_env *env, char *arg);

//checker.c
void			ft_check_duplicates(t_env *env);
void			ft_init_tab(char **av, t_env *env);
void			ft_init_arg(t_env *env);

// lst_utils.c
int				ft_list_add_back(t_lst **alst, t_lst *new);
void			ft_list_add_front(t_lst **alst, t_lst *new);
void			ft_list_clear(t_lst **lst);
t_lst			*ft_list_swap(t_lst *list_1, t_lst *list_2);
int				ft_list_size(t_lst *lst);

// lst_utils2.c
t_lst			*ft_list_last(t_lst *lst);
t_lst			*ft_list_last2(t_lst *lst);
void			ft_list_iter(t_lst *lst, int (f)(int));
void			ft_list_delone(t_lst *lst);
t_lst			*ft_list_new(int nb);

// debug.c
void			ft_list_print(t_lst *lst);
void			ft_print_env(t_env *env);

// ft_arg.c
void			ft_s(t_env *env, char c);
void			ft_p(t_env *env, char c);
void			ft_r(t_env *env, char c);
void			ft_rr(t_env *env, char c);

#endif
