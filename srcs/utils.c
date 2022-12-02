/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:46:06 by gscarama          #+#    #+#             */
/*   Updated: 2022/09/21 16:32:43 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	put_nbr_toindex(t_stacks *lst, int n)
{
	int		row;
	t_list	*tmp;

	row = 0;
	tmp = lst->stk;
	while (!(n > tmp->cont && n < tmp->next->cont)
		&& row < (lst->size - 2) && tmp->next != NULL)
	{
		tmp = tmp->next;
		row++;
	}
	tmp = tmp->next;
	return (tmp->cont);
}

t_list	*create_list(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
	int		row;

	row = 1;
	if (argc > 2)
		row++;
	lst = ft_lstnew(ft_atoi(argv[row - 1]));
	while (argv[row])
	{
		tmp = ft_lstnew(ft_atoi(argv[row]));
		ft_lstadd_back(&lst, tmp);
		row++;
	}
	check_dup(argc, argv, lst);
	return (lst);
}

void	printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("Arg: %i\n", tmp->cont);
		tmp = tmp->next;
	}
}

void	print_all_lst(t_data *lst)
{
	ft_printf("\n*****Stack A******\n");
	printlst(lst->a.stk);
	ft_printf("\n*****Stack B******\n");
	printlst(lst->b.stk);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(-1);
}
