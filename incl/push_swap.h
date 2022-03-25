/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:57:20 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/25 13:17:02 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>

void	ft_printflst(t_list *lst);

t_list	*create_list(int argc, char **argv);
void	ft_swap(t_list *lst);
void	algoritims(t_list *lst);

void	check_one_arg (char **argv);
void	check_mult_args (int argc, char **argv);

#endif