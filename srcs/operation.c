/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:05:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 13:42:11 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_sa(t_data *lst, int boll)
{
	if (lst->a.size > 1)
	{
		ft_swap(&lst->a.stk);
		if (boll == TRU)
			write(1, "sa\n", 3);
	}
}

void	ft_sb(t_data *lst, int boll)
{
	if (lst->b.size > 1)
	{
		ft_swap(&lst->b.stk);
		if (boll == TRU)
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_data *lst)
{
	ft_sa(lst, FALS);
	ft_sb(lst, FALS);
	write(1, "ss\n", 3);
}

void	ft_pa(t_data *lst)
{
	if (lst->a.size == 0)
		lst->a.stk = NULL;
	if (lst->b.size > 0)
	{
		lst->b.size -= 1;
		lst->a.size += 1;
		ft_push(&lst->b.stk, &lst->a.stk);
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_data *lst)
{
	if (lst->b.size == 0)
		lst->b.stk = NULL;
	if (lst->a.size > 0)
	{
		lst->a.size -= 1;
		lst->b.size += 1;
		ft_push(&lst->a.stk, &lst->b.stk);
		write(1, "pb\n", 3);
	}
}
