/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:15:58 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 13:52:00 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	tiny_sort(t_data *lst, int big, int small)
{
	while (!is_sorted(lst->a.stk))
	{
		if (lst->a.stk->cont == big)
			ft_ra(lst, TRU);
		else if (lst->a.stk->next->cont == small)
			ft_sa(lst, TRU);
		else
			ft_rra(lst, TRU);
	}
}

int	find_index(t_stacks *lst, int big)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst->stk;
	while (i < lst->size && tmp != NULL)
	{
		if (tmp->cont == big)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (2147483647);
}

void	index_sort(t_data *lst, t_stacks *stka, int big, char sig)
{
	int	index;
	int	len;

	index = find_index(stka, big);
	len = stka->size - 1;
	if (index > -1)
	{
		if (len - index < index)
			while (stka->stk->cont != big && sig == 'a')
				ft_rra(lst, TRU);
		else if (len - index >= index)
			while (stka->stk->cont != big && sig == 'a')
				ft_ra(lst, TRU);
		if (len - index < index)
			while (stka->stk->cont != big && sig == 'b')
				ft_rrb(lst, TRU);
		else if (len - index >= index)
			while (stka->stk->cont != big && sig == 'b')
				ft_rb(lst, TRU);
	}
}

void	medium_sort(t_data *lst, int big, int small)
{
	while (lst->a.size > 2)
	{
		if (lst->a.stk->cont == big
			|| lst->a.stk->cont == small)
			ft_ra(lst, TRU);
		else
			ft_pb(lst);
	}
	while (lst->b.size != 0)
	{
		big = biggest_nbr(lst->b.stk);
		index_sort(lst, &lst->b, big, 'b');
		if (lst->a.stk->cont < lst->b.stk->cont)
		{
			ft_ra(lst, TRU);
			ft_pa(lst);
		}
		else
			ft_pa(lst);
	}
	ft_rra(lst, TRU);
}

void	mini_sort(t_data *lst)
{
	int	big;
	int	small;

	big = biggest_nbr(lst->a.stk);
	small = smallest_nbr(lst->a.stk);
	if (lst->a.size <= 3)
		tiny_sort(lst, big, small);
	else
		medium_sort(lst, big, small);
}
