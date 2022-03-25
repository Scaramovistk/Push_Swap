/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/25 16:56:18 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc == 2)
		check_one_arg(argv);
	else if (argc > 2)
		check_mult_args(argc, argv);
	else
		ft_printf("\nError\n");
	lst = create_list(argc, argv);
	
	check_duplicate(lst);

	algoritims(lst);
	
	ft_printflst(lst);
	return (0);
}
