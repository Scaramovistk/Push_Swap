/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:15:58 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:21:58 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

	void	tiny_sort(t_data *lst, int big, int small)
	{
		while (!is_sorted(lst->a->stk))
		{
			if (lst->a->stk->content == big)
				ft_ra(lst);
			else if (lst->a->stk->next->content == small)
				ft_sa(lst);
			else
				ft_rra(lst);
		}
	}

	int	find_index(t_stacks *lst, int big)
	{
		int		i;
		t_list	*tmp;

		i = 0;
		tmp = lst->stk;
		while (i < lst->size)
		{
			if (tmp->content == big)
				return (i);
			tmp = tmp->next;
			i++;
		}
		return (2147483647);
	}

	void	sort_b(t_data *lst, t_stacks *stka, int big)
	{
		int	index;
		int	len;

		index = find_index(stka, big);
		len = stka->size - 1;
		if (index > -1)
		{
			if (len - index < index)
				while (stka->stk->content != big)
					ft_rrb(lst);
			else if (len - index >= index)
				while (stka->stk->content != big)
					ft_rb(lst);
		}
	}

	void	medium_sort(t_data *lst, int big, int small)
	{
		while (lst->a->size > 2)
		{
			if (lst->a->stk->content == big
				|| lst->a->stk->content == small)
				ft_ra(lst);
			else
				ft_pb(lst);
		}
		while (lst->b->size != 0)
		{
			big = biggest_nbr(lst->b->stk);
			
			sort_b(lst, lst->b, big);
			if (lst->a->stk->content < lst->b->stk->content)
			{
				ft_ra(lst);
				ft_pa(lst);
			}
			else
				ft_pa(lst);
		}
		ft_rra(lst);
	}

	void	mini_sort(t_data *lst)
	{
		int	big;
		int	small;

		big = biggest_nbr(lst->a->stk);
		small = smallest_nbr(lst->a->stk);
		if (lst->a->size <= 3)
			tiny_sort(lst, big, small);
		else
			medium_sort(lst, big, small);
	}
