/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:27 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:30:36 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift up all elements of stack 'b' by 1.
The first element becomes the last one."
RETURNS: 0 all good, 1 error*/
int	rb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	(void)(head_a);
	if (!*head_b || !(*head_b)->next)
		return (1);
	temp = (*head_b)->next;
	ft_stklast(*head_b)->next = *head_b;
	(*head_b)->next = NULL;
	(*head_b) = temp;
	return (0);
}
