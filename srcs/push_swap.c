/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:45:04 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:27:44 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_swap(int *head, int *tail)
{
	int	tmp;

	tmp = *head;
	*head = *tail;
	*tail = tmp;
}

void	ft_push(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	tmp = *lsta;
	*lsta = (*lsta)->next;
	tmp->next = *lstb;
	*lstb = tmp;
}

void	ft_rrr (t_list **lsta, t_list **lstb)
{
	ft_rra(lsta);
	ft_rrb(lstb);
	write(1, "rrr\n", 4);
}

void	algoritims(t_list *lsta)
{
	int		swaped;
	t_list	*head;

	head = lsta;
	while (lsta)
	{
		swaped = 0;
		if (lsta->next == NULL)
			break;
		if (lsta->content > lsta->next->content)
		{
			ft_swap(&lsta->content, &lsta->next->content);
			lsta = head;
			swaped = 1;
		}
		if (swaped == 0)
			lsta = lsta->next;
	}
}
