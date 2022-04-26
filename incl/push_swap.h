/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:57:20 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/26 16:25:57 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# define FALSE 0
# define TRUE 1

typedef struct s_stacks
{
	t_list	*stk;
	int		size;
}	t_stacks;

typedef struct s_data
{
	t_stacks	*a;
	t_stacks	*b;
	int			size;
	int			boll;
}	t_data;

void	check_args(char **argv);
void	check_dup(t_list *lst);
void	ft_error();

void	printlst(t_list *lst);
void	print_all_lst(t_data *lst);

t_list	*create_list(int argc, char **argv);
int		is_sorted(t_list *lst);
int		biggest_nbr(t_list *lst);
int		smallest_nbr(t_list *lst);

int		find_index(t_stacks *lst, int big);
void	sort_b(t_data *lst, t_stacks *stka, int big);
void	mini_sort(t_data *lst);

void	ft_push(t_list **lsta, t_list **lstb);
void	ft_swap(t_list **lst);
void	ft_sa(t_data *lst);
void	ft_sb(t_data *lst);
void	ft_ss(t_data *lst);
void	ft_pa(t_data *lst);
void	ft_pb(t_data *lst);
void	ft_rr(t_data *lst);
void	ft_rrr (t_data *lst);
void	ft_ra(t_data *lsta);
void	ft_rb(t_data *lstb);
void	ft_rra(t_data *lsta);
void	ft_rrb(t_data *lstb);

#endif