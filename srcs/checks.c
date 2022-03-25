/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:33:10 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/25 13:20:00 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	check_one_arg (char **argv)
{
	int	row;

	row = 0;
	while (argv[1][row])
	{
		if (!ft_isdigit(argv[1][row]) && argv[1][row] != ' '
			&& argv[1][row] != '-')
		{
			ft_printf("%s\nError\n", argv[1]);
			exit(0);
		}
		row++;
	}
	ft_putstr_fd("Input Correct\n", 1);
}

void	check_mult_args (int argc, char **argv)
{
	int	row;
	int	read;

	row = 1;
	while (row < argc)
	{
		read = 0;
		if(argv[row][0] == '-')
			read = 1;
		while (argv[row][read])
		{
			if (!ft_isdigit(argv[row][read]))
			{
				ft_printf("%s\nError\n", argv[row]);
				exit(0);
			}
			read++;
		}
		row++;
	}
	ft_putstr_fd("Input Correct\n", 1);
}

void	check_duplicate(t_list *lst)
{
	int	size;
	int	*nb;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	nb = malloc(sizeof(int *) * size);
}