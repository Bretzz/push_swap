/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:20:45 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 09:39:43 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift down all elements of stack 'b' by 1.
The last element becomes the first one."
RETURNS: 1 all good, 0 error*/
int	rrb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	
	(void)(head_a);
	if (!*head_b || !(*head_b)->next)
		return (0);
	temp = ft_stklast(*head_b);
	ft_stk_semi_last(*head_b)->next = NULL;
	temp->next = *head_b;
	*head_b = temp;
	ft_printf("rrb\n");
	return (1);
}
