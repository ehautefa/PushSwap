/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:38:36 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 17:54:53 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_UTILS_H
# define LST_UTILS_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_lst
{
	int				num;
	struct s_lst	*next;
}				t_lst;

/*
**  lst_utils.c
*/
int				ft_list_add_back(t_lst **alst, t_lst *new);
void			ft_list_add_front(t_lst **alst, t_lst *new);
void			ft_list_clear(t_lst **lst);
t_lst			*ft_list_swap(t_lst *list_1, t_lst *list_2);
int				ft_list_size(t_lst *lst);

/*
**  lst_utils2.c
*/
t_lst			*ft_list_last(t_lst *lst);
t_lst			*ft_list_last2(t_lst *lst);
void			ft_list_iter(t_lst *lst, int (f)(int));
void			ft_list_delone(t_lst *lst);
t_lst			*ft_list_new(int nb);

#endif
