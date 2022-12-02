/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:33:10 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/22 13:49:46 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_free_split(int argc, char **argv)
{
	int	row;

	row = 0;
	if (argc == 2)
	{
		while (argv[row])
		{
			free(argv[row]);
			row++;
		}
		free(argv);
	}
}

void	ft_free_lst(t_list *lst)
{
	int		row;
	int		size;
	t_list	*read;

	size = ft_lstsize(lst);
	row = 0;
	while (row < size - 1)
	{
		read = lst;
		while (read->next->next != NULL)
			read = read->next;
		free(read->next);
		read->next = NULL;
		row++;
	}
	free(lst);
}

void	check_args(int argc, char **argv)
{
	int	row;
	int	read;

	row = 1;
	while (argv[row])
	{
		read = 0;
		if (argv[row][0] == '-' && ft_isdigit(argv[row][1]))
			read = 1;
		while (argv[row][read])
		{
			if (!ft_isdigit(argv[row][read]))
			{
				ft_free_split(argc, argv);
				ft_error();
			}
			read++;
		}
		row++;
	}
}

void	check_dup(int argc, char **argv, t_list *lst)
{
	t_list	*lrow;
	int		dup;

	while (lst)
	{
		dup = 0;
		lrow = lst;
		while (lrow)
		{
			if (lst->cont == lrow->cont)
				dup++;
			if (dup == 2)
			{
				ft_free_lst(lst);
				ft_free_split(argc, argv);
				ft_error();
			}
			lrow = lrow->next;
		}
		lst = lst->next;
	}
}
