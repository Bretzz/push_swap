/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:45:07 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 09:39:05 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift up all elements of stack 'a' by 1.
The first element becomes the last one"
RETURNS: 1 all good, 0 error*/
int	ra(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	(void)(head_b);
	if (!*head_a || !(*head_a)->next)
		return (0);
	temp = (*head_a)->next;
	ft_stklast(*head_a)->next = *head_a;
	(*head_a)->next = NULL;
	*head_a = temp;
	ft_printf("ra\n");
	return (1);
}
