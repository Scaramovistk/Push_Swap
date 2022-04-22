/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:14:13 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:19:46 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if(lst->content > lst->next->content)
		{
			return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}

int	biggest_nbr(t_list *lst)
{
	int	nbr;

	nbr = lst->content;
	while (lst)
	{
		if (lst->content > nbr)
			nbr = lst->content;
		lst = lst->next;
	}
	return (nbr);
}

int	smallest_nbr(t_list *lst)
{
	int	nbr;

	nbr = lst->content;
	while (lst)
	{
		if (lst->content < nbr)
			nbr = lst->content;
		lst = lst->next;
	}
	return (nbr);
}
