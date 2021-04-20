/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:45:10 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/20 11:00:16 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_H
# define CHECKER_H
#include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_env
{
	int		*tab_a;
	int		*tab_b;
	char	**arg;
	int		size;
	int		nb_arg;
}				t_env;

int		ft_check_integer(char *str);
void	ft_print_error_and_free(t_env *env);
int		ft_checker_error(int ac, char **av, t_env *env);
void	ft_init_tab(char **av, t_env *env);
void	ft_init_arg(int	ac, char **av, t_env *env);



#endif
