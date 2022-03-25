/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:45:04 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/25 16:56:13 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// t_list	*create_list(int argc, char **argv)
// {
// 	t_list	*lst;
// 	t_list	*tmp;
// 	char	**str;
// 	int		row;

// 	row = 1;
// 	if (argc == 2)
// 	{
// 		str = ft_split(argv[1], ' ');
// 		lst = ft_lstnew(ft_atoi(str[0]));
// 		while (str[row])
// 		{
// 			tmp = ft_lstnew(ft_atoi(str[row]));
// 			ft_lstadd_back(&lst, tmp);
// 			row++;
// 		}
// 		return (lst);
// 	}
// 	row += 1;
// 	lst = ft_lstnew(ft_atoi(argv[1]));
// 	while (row < argc)
// 	{
// 		tmp = ft_lstnew(ft_atoi(argv[row]));
// 		ft_lstadd_back(&lst, tmp);
// 		row++;
// 	}
// 	return (lst);
// }

void	ft_print_arg(char **argv)
{
	int	row;

	row = 0;
	while (argv[row])
	{
		printf("Arg: %s\n", argv[row]);
		row++;
	}
}

t_list	*create_list(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
	int		row;

	row = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		row += 1;
	lst = ft_lstnew(ft_atoi(argv[row]));
	row++;
	while (argv[row] || row < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[row]));
		ft_lstadd_back(&lst, tmp);
		row++;
	}
	ft_printflst(lst);
	return (lst);
}

void	ft_swap(t_list *head, t_list *tail)
{
	int	tmp;

	tmp = head->content;
	head->content = tail->content;
	tail->content = tmp;
}

// void	ft_pull(t_list *obj1, t_list *obj2)
// {
	
// }

void	algoritims(t_list *lst)
{
	int		swaped;
	t_list	*head;

	head = lst;
	while (lst)
	{
		swaped = 0;
		if (lst->next == NULL)
			break;
		if (lst->content > lst->next->content)
		{
			//printf("\nSwap %d and %d\n", lst->content, lst->next->content);
			ft_swap(lst, lst->next);
			lst = head;
			swaped = 1;
		}
		if (swaped == 0)
			lst = lst->next;
	}
}
