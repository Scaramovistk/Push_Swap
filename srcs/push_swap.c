/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:45:04 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 13:52:22 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_swap(t_list **lst)
{
	int	tmp;

	tmp = (*lst)->cont;
	(*lst)->cont = (*lst)->next->cont;
	(*lst)->next->cont = tmp;
}

void	ft_push(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	tmp = *lsta;
	*lsta = (*lsta)->next;
	tmp->next = *lstb;
	*lstb = tmp;
}

void	ft_rrr(t_data *lst)
{
	ft_rra(lst, FALS);
	ft_rrb(lst, FALS);
	write(1, "rrr\n", 4);
}
