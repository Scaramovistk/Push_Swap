/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:45:02 by gscarama          #+#    #+#             */
/*   Updated: 2022/04/04 15:27:55 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;

	lstb = ft_lstnew(8);
	lsta = create_list(argv);

	ft_ra(&lsta);
	
	printf("LISTA\n");
	ft_printflst(lsta);
	// printf("LISTB\n");
	// ft_printflst(lstb);
	return (0);
}