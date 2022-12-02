/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:14:13 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 13:52:55 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->cont > lst->next->cont)
		{
			return (FALS);
		}
		lst = lst->next;
	}
	return (TRU);
}

int	biggest_nbr(t_list *lst)
{
	int	nbr;

	nbr = lst->cont;
	while (lst)
	{
		if (lst->cont > nbr)
			nbr = lst->cont;
		lst = lst->next;
	}
	return (nbr);
}

int	smallest_nbr(t_list *lst)
{
	int	nbr;

	nbr = lst->cont;
	while (lst)
	{
		if (lst->cont < nbr)
			nbr = lst->cont;
		lst = lst->next;
	}
	return (nbr);
}

int	get_moves(t_stacks *stk, int index)
{
	index = find_index(stk, index);
	if (index <= stk->size / 2 || index == 2147483647)
		return (index);
	else
		return ((stk->size + 1) - index);
}

int	get_index(t_list *lst, int nbr, int size)
{
	int		row;
	int		index;
	t_list	*tmp;

	tmp = lst;
	row = 0;
	index = 0;
	while (row < size && tmp != NULL)
	{
		if (nbr > tmp->cont)
			index++;
		tmp = tmp->next;
		row++;
	}
	return (index);
}
