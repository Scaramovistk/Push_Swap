/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:14:13 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/07 18:17:12 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	partition(t_list *lst, int low, int high)
{
	int	pivot;
	int	limiter;
	int	nextpivot;

	limiter = low;
	nextpivot = low;

	t_list	*begin;
	t_list	*last;
	int		row;

	row = 0;
	last = lst;
	while (last->next && row < high)
	{
		last = last->next;
		row++;
	}
	pivot = last->content;
	
	row = 0;
	begin = lst;
	while (begin->next && row < low)
	{
		begin = begin->next;
		row++;
	}
	//printf("pivo:%d\nlow:%d\nrow;%d\n", tmp->content, low, row);
	t_list	*read;

	read = begin;
	while (limiter < high && read->next)//change limiter by low
	{
		if (read->content < pivot)
		{
			ft_swap(&begin->content, &read->content);
			begin = begin->next;
			nextpivot++;
		}
		read = read->next;
		limiter++;
	}

	ft_swap(&begin->content, &last->content);
	return (nextpivot);
}

void	quicksort_recursion(t_list *lst, int low, int high)
{
	int	pivot;

//	printf("L%d H%d\n", low, high);
	if (low < high)
	{
		pivot = partition(lst, low, high);
		//printf("***********\nPivot%d\n", pivot);
		//ft_printflst(lst);
		quicksort_recursion(lst, low, pivot - 1);
		quicksort_recursion(lst, pivot + 1, high);
	}
}

void	quicksort(t_list *lst, int lenght)
{
	quicksort_recursion(lst, 0, lenght);
}
