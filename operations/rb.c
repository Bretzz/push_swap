/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:03:27 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 14:16:03 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift up all elements of stack 'b' by 1.
The first element becomes the last one."
RETURNS: 1 all good, 0 error*/
int	rb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	(void)(head_a);
	if (!*head_b || !(*head_b)->next)
		return (0);
	temp = (*head_b)->next;
	ft_stklast(*head_b)->next = *head_b;
	(*head_b)->next = NULL;
	*head_b = temp;
	ft_printf("rb\n");
	return (1);
}
