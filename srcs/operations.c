/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:05:44 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:21:29 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_ra(t_data *lst)
{
	t_list	*last;
	t_list	*tmp;

	last = lst->a->stk;
	while (last->next)
		last = last->next;
	tmp = lst->a->stk->next;
	last->next = lst->a->stk;
	lst->a->stk->next = NULL;
	lst->a->stk = tmp;
	//if (lst->boll == TRUE)
		write(1, "ra\n", 3);
}

void	ft_rb(t_data *lst)
{
	t_list	*last;
	t_list	*tmp;

	last = lst->b->stk;
	while (last->next)
		last = last->next;
	tmp = lst->b->stk->next;
	last->next = lst->b->stk;
	lst->b->stk->next = NULL;
	lst->b->stk = tmp;
	//if (lst->boll == TRUE)
		write(1, "rb\n", 3);
}

void	ft_rr(t_data *lst)
{
	lst->boll = FALSE;
	ft_ra(lst);
	ft_rb(lst);
	lst->boll = TRUE;
	write(1, "rr\n", 3);
}

void	ft_rra(t_data *lst)
{
	t_list	*last;
	t_list	*tmp;

	last = lst->a->stk;
	while (last->next)
	{
		if (last->next)
			tmp = last;
		last = last->next;
	}
	last->next = lst->a->stk;
	tmp->next = NULL;
	lst->a->stk = last;
	//if (lst->boll == TRUE)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_data *lst)
{
	t_list	*last;
	t_list	*tmp;

	last = lst->b->stk;
	while (last->next)
	{
		if (last->next)
			tmp = last;
		last = last->next;
	}
	last->next = lst->b->stk;
	tmp->next = NULL;
	lst->b->stk = last;
	//if (lst->boll == TRUE)
		write(1, "rrb\n", 4);
}