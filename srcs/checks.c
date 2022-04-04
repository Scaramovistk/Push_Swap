/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:33:10 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:27:00 by gscarama         ###   ########.fr       */
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
		if(argv[row][0] == '-')
			read = 1;
		while (argv[row][read])
		{
			if (!ft_isdigit(argv[row][read]))
			{
				ft_printf("%s\nError\n", argv[row]);
				exit(-1);
			}
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
			if (lst->content == lrow->content)
				dup++;
			if (dup == 2)
			{
				ft_printf("Duplicate Input: %d\n", lrow->content);
				exit(-1);
			}
			lrow = lrow->next;
		}
		lst = lst->next;
	}
	ft_putstr_fd("Input Correct\n", 1);
}
