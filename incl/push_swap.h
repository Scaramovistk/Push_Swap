/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:57:20 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:26:35 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>

void	ft_printflst(t_list *lst);

t_list	*create_list(char **argv);
void	ft_swap(int *head, int *tail);
void	ft_push(t_list **lsta, t_list **lstb);
void	algoritims(t_list *lst);

void	check_args(char **argv);
void	check_dup(t_list *lst);

void	ft_sa(int *head, int *tail);
void	ft_sb(int *head, int *tail);
void	ft_ss(t_list *lsta, t_list *lstb);
void	ft_pa(t_list *lsta, t_list *lstb);
void	ft_pb(t_list *lsta, t_list *lstb);
void	ft_ra(t_list **lsta);
void	ft_rb(t_list **lstb);
void	ft_rr(t_list **lsta, t_list **lstb);
void	ft_rra(t_list **lsta);
void	ft_rrb(t_list **lstb);
void	ft_rrr (t_list **lsta, t_list **lstb);

#endif