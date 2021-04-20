/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:41:44 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/20 10:42:55 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
#include <stdio.h>
int		ft_check_integer(char *str);
void	ft_print_error(int *tab);
int		ft_check_error(int ac, char **av);

typedef struct	s_env
{
	int		*tab_a;
	int		*tab_b;
	char	**arg;
	int		size;
	int		nb_arg;
}				t_env;

#endif
