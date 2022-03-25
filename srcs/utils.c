/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:46:06 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/25 12:46:16 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_printflst(t_list *lst)
{
	while (lst)
	{
		printf("Arg: %i\n", lst->content);
		lst = lst->next;
	}
}