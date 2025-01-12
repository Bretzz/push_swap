/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:19:37 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 06:00:25 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements."
RETURNS: 1 all good, 0 error*/
int	sa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*third;
	t_stack	*second;

	(void)(head_b);
	if (!*head_a || !(*head_a)->next)
		return (0);
	third = (*head_a)->next->next;
	second = (*head_a)->next;
	(*head_a)->next = third;
	second->next = *head_a;
	*head_a = second;
	return (1);
}
