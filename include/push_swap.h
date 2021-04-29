/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:44 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 16:57:32 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	int		*size_bloc;
	int		nb_bloc;
}				t_env;


// error.c
int				ft_check_integer(char *str);
void			ft_print_error_and_free(t_env *env, int error);
int				ft_checker_error(int ac, char **av, t_env *env);

//push_swap.c
void			ft_check_duplicates(t_env *env);
void			ft_init_tab(char **av, t_env *env);

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


// ft_arg.c
void			ft_s(t_env *env, char c);
void			ft_p(t_env *env, char c);
void			ft_r(t_env *env, char c);
void			ft_rr(t_env *env, char c);

// sort_3.c

void			sort_3(t_env *env);
int				find_biggest_index(t_lst *lst);
int				ft_find_median(t_env *env, int size, float *med, char c);
int				*ft_sort_by_insertion_tab(int *tab, int size);


// bloc_sort.c
void			ft_find_low_value(t_env *env, float med, int *size);
void			cut_heap(t_env *env);
int				find_size_bloc(int size, int lim);

// sort_bloc_utils.c
t_lst			*find_i_element_list(t_lst *lst, int i);
int				find_number_of_rev_rot(t_lst *lst, float med, int size, char c);
int				find_number_of_rot(t_lst *lst, float med, char c);

// retur_to_a.c
int				ft_find_value(t_env *env, float med, int *size, char c);
void			replace_last_bloc(t_env *env, char c, int size);
int				*deplace_bloc(int size, t_env *env, char c, int *size_bloc);
void			cut_bloc(t_env *env, char c, int size);
void			ft_retur_to_b_heap(t_env *env);

// retur_to_a_utils.c
void			ft_adjust_rotation(t_env *env, int *nb_r, int j, char c);
int				list_is_sort(t_env *env, char c, int size);
char			opposite(char c);
void			ft_repeat(int size, t_env *env, char c);

// retur_to_a_100.c
void			ft_adjust_order_bloc(t_env *env, int *tab, int i);
void			sort_bloc(t_env *env, int i);
int				find_num_of_rev_rot(t_lst *lst, int to_find, int size);
int				find_num_of_rot(t_lst *lst, int to_find);

#endif
