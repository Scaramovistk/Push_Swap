/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:05:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:08:26 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_sa(int *head, int *tail)
{
	write(1, "sa\n", 3);
	ft_swap(head, tail);
}

void	ft_sb(int *head, int *tail)
{
	write(1, "sb\n", 3);
	ft_swap(head, tail);
}

void	ft_ss(t_list *lsta, t_list *lstb)
{
	write(1, "ss\n", 3);
	ft_sa(&lsta->content, &lsta->next->content);
	ft_sb(&lstb->content, &lstb->next->content);
}

void	ft_pa(t_list *lsta, t_list *lstb)
{
	write(1, "pa\n", 3);
	ft_push(&lstb, &lsta);
}

void	ft_pb(t_list *lsta, t_list *lstb)
{
	write(1, "pa\n", 3);
	ft_push(&lsta, &lstb);
}
