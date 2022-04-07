/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/07 17:15:29 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		lenght;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc == 1)
		ft_error();
	check_args(argv);
	
	lst = create_list(argc, argv);
	lenght = ft_lstsize(lst);
	
	quicksort(lst, lenght);
	
	ft_printflst(lst);
	return (0);
}
