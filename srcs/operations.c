/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:05:44 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:26:03 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_ra(t_list **lsta)
{
	t_list	*last;
	t_list	*tmp;

	last = *lsta;
	while (last->next)
		last = last->next;
	tmp = (*lsta)->next;
	last->next = *lsta;
	(*lsta)->next = NULL;
	*lsta = tmp;
	write(1, "rra\n", 3);
}

void	ft_rb(t_list **lstb)
{
	t_list	*last;
	t_list	*tmp;

	last = *lstb;
	while (last->next)
		last = last->next;
	tmp = (*lstb)->next;
	last->next = *lstb;
	(*lstb)->next = NULL;
	*lstb = tmp;
	write(1, "rra\n", 3);
}

void	ft_rr(t_list **lsta, t_list **lstb)
{
	ft_ra(lsta);
	ft_rb(lstb);
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **lsta)
{
	t_list	*last;
	t_list	*tmp;

	last = *lsta;
	while (last->next)
	{
		if (last->next)
			tmp = last;
		last = last->next;
	}
	last->next = *lsta;
	tmp->next = NULL;
	*lsta = last;
	write(1, "ra\n", 3);
}

void	ft_rrb(t_list **lstb)
{
	t_list	*last;
	t_list	*tmp;

	last = *lstb;
	while (last->next)
	{
		if (last->next)
			tmp = last;
		last = last->next;
	}
	last->next = *lstb;
	tmp->next = NULL;
	*lstb = last;
	write(1, "rb\n", 3);
}
