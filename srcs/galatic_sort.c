/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galatic_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:22:35 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 17:12:57 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	pre_sort(t_data *lst, int small, int big)
{
	int	size;

	size = lst->a.size;
	while (lst->a.size > (size / 2) + 2)
	{
		if (lst->a.stk->cont == small
			|| lst->a.stk->cont == big)
			ft_ra(lst, TRU);
		else if (lst->a.stk->cont <= size / 2)
			ft_pb(lst);
		else
			ft_ra(lst, TRU);
	}
	while (!is_sorted(lst->a.stk))
	{
		if (lst->a.stk->cont == small
			|| lst->a.stk->cont == big)
			ft_ra(lst, TRU);
		else
			ft_pb(lst);
	}
}

void	best_comb(t_data *lst)
{
	int		moves;
	int		row;
	int		atmp;
	t_list	*btmp;

	row = 0;
	moves = lst->a.size + lst->b.size;
	btmp = lst->b.stk;
	while (row < lst->b.size)
	{
		atmp = put_nbr_toindex(&lst->a, btmp->cont);
		if (get_moves(&lst->a, atmp) + get_moves(&lst->b, btmp->cont) < moves)
		{
			lst->a.top = atmp;
			lst->b.top = btmp->cont;
			moves = get_moves(&lst->a, atmp) + get_moves(&lst->b, btmp->cont);
		}
		btmp = btmp->next;
		row++;
	}
	index_sort(lst, &lst->a, lst->a.top, 'a');
	index_sort(lst, &lst->b, lst->b.top, 'b');
}

void	normalize(t_stacks *lst)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*indexlst;
	int		nbr;

	tmp = lst->stk;
	indexlst = ft_lstnew(get_index(tmp, lst->stk->cont, lst->size));
	head = indexlst;
	while (lst->stk->next != NULL)
	{
		lst->stk = lst->stk->next;
		nbr = get_index(tmp, lst->stk->cont, lst->size);
		indexlst->next = ft_lstnew(nbr);
		indexlst = indexlst->next;
	}
	ft_free_lst(tmp);
	lst->stk = head;
}

void	galactic_sort(t_data *lst)
{
	int	big;
	int	small;

	normalize(&lst->a);
	big = biggest_nbr(lst->a.stk);
	small = smallest_nbr(lst->a.stk);
	pre_sort(lst, small, big);
	while (lst->b.size != 0 && lst->b.stk != NULL)
	{
		best_comb(lst);
		if (lst->a.stk->cont < lst->b.stk->cont)
		{
			ft_ra(lst, TRU);
			ft_pa(lst);
		}
		else
			ft_pa(lst);
	}
	index_sort(lst, &lst->a, small, 'a');
}
