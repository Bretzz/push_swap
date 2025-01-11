/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:28:47 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:30:57 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements."
RETURNS: 0 all good, 1 error*/
int	sb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*third;
	t_stack	*second;

	(void)(head_a);
	if (!*head_b || !(*head_b)->next)
		return (1);
	third = (*head_b)->next->next;
	second = (*head_b)->next;
	(*head_b)->next = third;
	second->next = *head_b;
	*head_b = second;
	return (0);
}
