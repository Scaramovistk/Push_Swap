/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:45:04 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:20:57 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_swap(t_list **lst)
{
	int	tmp;

	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	ft_push(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	tmp = *lsta;
	*lsta = (*lsta)->next;
	tmp->next = *lstb;
	*lstb = tmp;
}

void	ft_rrr (t_data *lst)
{
	lst->boll = FALSE;
	ft_rra(lst);
	ft_rrb(lst);
	lst->boll = TRUE;
	write(1, "rrr\n", 4);
}

