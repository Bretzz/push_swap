/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:20:45 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:30:46 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift down all elements of stack 'b' by 1.
The last element becomes the first one."
RETURNS: 0 all good, 1 error*/
int	rrb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	
	(void)(head_a);
	if (!*head_b || !(*head_b)->next)
		return (1);
	temp = ft_stklast(*head_b);
	ft_stk_semi_last(*head_b)->next = NULL;
	temp->next = *head_b;
	*head_b = temp;
	return (0);
}
