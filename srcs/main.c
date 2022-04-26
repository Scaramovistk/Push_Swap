/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/26 16:29:54 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	pre_sort(t_data *lst, t_stacks *stk, int small, int big)
{
	while (lst->a->size > (lst->size / 2) + 2)
	{
		if (lst->a->stk->content == small
			|| lst->a->stk->content == big)
			ft_ra(lst);
		else if (lst->a->stk->content <= lst->size /2)
			ft_pb(lst);
		else
			ft_ra(lst);
	}
	while (!is_sorted(lst->a->stk))
	{
		if (lst->a->stk->content == small
			|| lst->a->stk->content == big)
			ft_ra(lst);
		else
			ft_pb(lst);
	}
}

int	put_nbr_toindex(t_list *lst, int size, int n)
{
	int		row;
	t_list	*tmp;

	row = 0;
	tmp = lst;
	while (!(n > lst->next->content && n < lst->next->content) && row < (size - 2))
	{
		row++;
		lst = lst->next;
	}
	lst = tmp;
	return (row + 1);
}

int	get_moves(t_stacks *stk, int index)
{
	int	index;

	index = find_index(stk, index);
	if (index <= stk->size / 2 || index == 2147483647)
		return (index);
	else
		return ((stk->size + 1) - index);
}

void	best_comb(t_data *lst)
{
	int		index;
	int		moves;
	int		tmp_a;
	int		tmp_b;
	int		row;
	t_list	*atmp;
	t_list	*btmp;

	index = 0;
	row = 0;
	moves = lst->size - 1;
	while (row < lst->b->size)
	{
		tmp_b = lst->b->stk;
		index = put_nbr_toindex(lst->b->stk, lst->b->size, tmp_b);
		tmp_a = 0;
		while (tmp_a < index && lst->a->stk)
		{
			lst->a->stk = lst->a->stk->next;
			tmp_a++;
		}
		tmp_a = lst->a->stk;
		if (get_moves(lst->a->stk, tmp_a) + get_moves(lst->b, tmp_b) < moves)
		{
			//lst->a->top = tmp_a
			//lst->b->top = tmp_b
			moves = get_moves(lst->a->stk, tmp_a) + get_moves(lst->b->stk, tmp_b);
		}
		row++;
	}
	index_sort(lst, lst->a, lst->a, 'a');
	index_sort(lst, lst->b,lst->b, 'b');
}

void	galactic_sort(t_data *lst)
{
	int			big;
	int			small;
	t_stacks	*stk;

	stk = lst->a->stk;
	big = biggest_nbr(lst->a->stk);
	small = smallest_nbr(lst->a->stk);
	pre_sort(lst, stk, small, big);
	while (lst->b->size != 0)
	{
		best_comb(lst);
		if (lst->a->stk->content < lst->b->stk->content)
		{
			ft_ra(lst);
			ft_pa(lst);
		}
		else
			ft_pa(lst);
	}
	index_sort(lst, lst->a, big, 'a');
}

int	main(int argc, char **argv)
{
	t_data	*lst;
//Init Data
	lst = malloc(sizeof(lst));
	lst->a = malloc(sizeof(lst->a));
	lst->b = malloc(sizeof(lst->b));
	lst->b->stk = NULL;
	lst->a->size = argc - 1;
	lst->size = argc - 1;
	//lst->boll = malloc(sizeof(int));
	lst->boll = TRUE;

//Checks
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc == 1)
		ft_error();
	check_args(argv);
//List Data
	//printf("%d\n", (int)lst->boll);
	lst->a->stk = create_list(argc, argv);
	//printf("%d\n", (int)lst->boll);
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
	//FREE data
	return (0);
}
