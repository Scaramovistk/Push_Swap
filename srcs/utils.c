/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:46:06 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/22 15:20:07 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
	int		row;

	row = 0;
	if (argc > 2)
		row++;
	lst = ft_lstnew(ft_atoi(argv[row]));
	row++;
	while (argv[row])
	{
		tmp = ft_lstnew(ft_atoi(argv[row]));
		ft_lstadd_back(&lst, tmp);
		row++;
	}
	check_dup(lst);
	return (lst);
}

void	printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("Arg: %i\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_all_lst(t_data *lst)
{
	ft_printf("\n*****Stack A******\n");
	printlst(lst->a->stk);
	ft_printf("\n*****Stack B******\n");
	printlst(lst->b->stk);
}

void	ft_error()
{
	ft_printf("Error\n");
	exit(-1);
}
