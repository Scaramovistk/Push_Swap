/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/22 13:50:53 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	lst;

	lst.b.stk = NULL;
	lst.b.size = 0;
	lst.size = argc - 1;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc == 1)
		ft_error();
	check_args(argc, argv);
	lst.a.stk = create_list(argc, argv);
	lst.a.size = ft_lstsize(lst.a.stk);
	if (!(is_sorted(lst.a.stk)))
	{
		if (lst.a.size < 10)
			mini_sort(&lst);
		else
			galactic_sort(&lst);
	}
	ft_free_lst(lst.a.stk);
	ft_free_split(argc, argv);
	free(lst.b.stk);
	return (0);
}
