/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:33:10 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 13:51:42 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_args(char **argv)
{
	int	row;
	int	read;

	row = 1;
	while (argv[row])
	{
		read = 0;
		if (argv[row][0] == '-')
			read = 1;
		while (argv[row][read])
		{
			if (!ft_isdigit(argv[row][read]))
				ft_error();
			read++;
		}
		row++;
	}
}

void	check_dup(t_list *lst)
{
	t_list	*head;
	t_list	*lrow;
	int		dup;

	head = lst;
	while (lst)
	{
		dup = 0;
		lrow = head;
		while (lrow)
		{
			if (lst->cont == lrow->cont)
				dup++;
			if (dup == 2)
				ft_error();
			lrow = lrow->next;
		}
		lst = lst->next;
	}
}

void	check_malloc(void *str)
{
	if (!str)
		exit(1);
}
