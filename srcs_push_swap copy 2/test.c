/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehautefa <ehautefa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:15:00 by ehautefa          #+#    #+#             */
/*   Updated: 2021/04/29 11:15:03 by ehautefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_adjust_order_bloc(t_env *env, int *tab, int i)
{
	int		j;
	int		up;
	int		down;

	j = -1;
	while (++j < env->size_bloc[i])
	{
		while (env->b->num != tab[j])
		{
			down = find_num_of_rev_rot(env->b, tab[j],
				ft_list_size(env->b)) + 1;
			up = find_num_of_rot(env->b, tab[j]) + 1;
			if (up == 1)
				ft_s(env, 'b');
			else if (up <= down)
				while (--up > 0)
					ft_r(env, 'b');
			else
				while (--down > 0)
					ft_rr(env, 'b');
		}
		ft_p(env, 'a');
	}
}

void	ft_find_value(t_env *env, float med, int *size, char c)
{
	int		down;
	int		up;
	t_lst	*lst;

	lst = env->a;
	if (c == 'b')
		lst = env->b;
	if ((c == 'a' && (float)lst->num >= med) || (c == 'b' && (float)lst->num <= med))
	{
		down = find_number_of_rev_rot(lst, med, *size, c) + ft_list_size(lst) - *size;
		up = find_number_of_rot(lst, med, c) + 1;
		if (up == 1 || up == 2)
			ft_s(env, c);
		else if (up <= down)
			while (--up > 0)
				ft_r(env, c);
		else
			while (--down > 0)
				ft_rr(env, c);
	}
	c = c == 'a' ? 'b' : 'a';
	ft_p(env, c);
	*size -= 1;
}

void	sort_2(t_env *env, char c)
{
	if (c == 'a')
	{
		if (env->a->num > env->a->next->num)
			ft_s(env, c);
	}
	if (c == 'b')
	{
		if (env->b->num < env->b->next->num)
			ft_s(env, c);
	}
	c = c == 'a' ? 'b' : 'a';
	ft_p(env, c);
	ft_p(env, c);
}

int		ft_transfer_bloc(t_env *env, int size, char c)
{
	float	med;
	int		lim;
	int		i;
	int		nb_bloc;
	int		*size_bloc;

	nb_bloc = find_size_length_bloc(size);
	size_bloc = malloc(nb_bloc * sizeof(int));
	if (size_bloc == NULL)
		ft_print_error_and_free(env, 1);
	i = -1;
	while (size > 2)
	{
		if (ft_find_median(env, size, &med, c) == -1)
			ft_print_error_and_free(env, 1);
		lim = size / 2 + size % 2;
		size_bloc[++i] = size - lim;
		while (size > lim)
			ft_find_value(env, med, &size, c);
	}
	sort_2(env, c);
	return(size_bloc[i]);
}