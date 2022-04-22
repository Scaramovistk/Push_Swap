/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:22:21 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

	void	galactic_sort(t_data *lst)
	{
		int	big;
		int	small;

		big = biggest_nbr(lst->a->stk);
		small = smallest_nbr(lst->a->stk);
		
	}

int	main(int argc, char **argv)
{
	t_data	*lst;
//Checks
	lst = malloc(sizeof(lst));
	lst->a = malloc(sizeof(lst->a));
	lst->b = malloc(sizeof(lst->b));
	lst->b->stk = NULL;
	//lst->boll = malloc(sizeof(int));
	lst->boll = TRUE;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc == 1)
		ft_error();
	check_args(argv);
//List Data
	//printf("%d\n", (int)lst->boll);
	lst->a->stk = create_list(argc, argv);
	//printf("%d\n", (int)lst->boll);
	lst->a->size = argc - 1;
//Sort Stack

	if(!(is_sorted(lst->a->stk)))
	{
		if (lst->a->size < 10)
			mini_sort(lst);
		else
			galactic_sort(lst);
	}

	// ft_rrr(lst);
	// ft_rr(lst);
	// ft_ss(lst);
	printlst(lst->a->stk);
	//free data
	return (0);
}
