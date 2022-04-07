/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:46:06 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/06 15:25:44 by gscarama         ###   ########.fr       */
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

void	ft_printflst(t_list *lst)
{
	while (lst)
	{
		printf("Arg: %i\n", lst->content);
		lst = lst->next;
	}
}

void	ft_error()
{
	ft_printf("Error\n");
	exit(-1);
}