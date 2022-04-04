/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:21:16 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc == 1)
		{
			ft_printf("Error\n");
			return (-1);
		}
	check_args(argv);
	
	lst = create_list(argv);

	algoritims(lst);
	
	ft_printflst(lst);
	return (0);
}
